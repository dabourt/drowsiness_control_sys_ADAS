import cv2
import os
################## Drowsiness Detection App lib ####################
##from jedi.api.completion_cache import save_entry
from keras.models import load_model
import numpy as np
from pygame import mixer
####################################################################

################## Keyboord lib ####################################
from pynput import keyboard
from pynput.keyboard import Key
####################################################################
import time

################## MQTT Lib     ####################################
import paho.mqtt.client as paho
####################################################################

TOPIC = 'blackbill/LED'
Drossniess_Flag = 0


def left_key_handler():
    global car_speed
    global car_st
    global car_dir
    if car_st < 30:
        car_st += 10


def right_key_handler():
    global car_speed
    global car_st
    global car_dir
    if car_st > -30:
        car_st -= 10


def up_key_handler():
    global car_speed
    global car_st
    global car_dir
    if car_speed == 0 or (car_speed <= 70 and car_dir == 1):
        car_speed = START_SPEED
        car_dir = 0
    elif car_speed > 70 and car_dir == 1:
        car_speed -= 5
    else:
        if car_speed < 99:
            car_speed += 5

        if car_speed >= 99:
            car_speed = 99

    car_st = 0

def down_key_handler():
    global car_speed
    global car_st
    global car_dir
    if car_speed == 0 or (car_speed <= 70 and car_dir == 0):
        car_speed = START_SPEED
        car_dir = 1
    elif car_speed > 70 and car_dir == 0:
        car_speed -= 5
    else:
        if car_speed < 99:
            car_speed += 5

        if car_speed >= 99:
            car_speed = 99

    car_st = 0


def space_key_handler():
    global car_speed
    global car_st
    global car_dir
    car_speed = 0
    car_st = 0
    car_dir = 0


def send_massege():
    global car_speed
    global car_st
    global car_dir
    sign = 0

    if car_speed == 100:
        car_speed -= 1

    if car_st < 0:
        sign = ""
    massege = 'KS'+str(car_speed).zfill(2)+" "+str(sign)+str(car_st).zfill(2)+" "+str(car_dir)
    print(massege)
    (rc, mid) = client.publish(TOPIC, str(massege), qos=1)


def on_key_release(key):
    global score
    match key:
        case Key.right:
            right_key_handler()
        case Key.left:
            left_key_handler()
        case Key.up:
            up_key_handler()
        case Key.down:
            down_key_handler()
        case key.space:
            space_key_handler()
        case Key.esc:
            exit()
        case Key.shift:
            score = 0
        case _:
            print("Please use arrow keys and space only")

    send_massege()

def send_massege_drow(drossniss_flag):
    massege = "KDRO LEV "+str(drossniss_flag)
    print(massege)
    (rc, mid) = client.publish(TOPIC, str(massege), qos=1)

mixer.init()
sound = mixer.Sound ('alarm.wav')
sound_1 = mixer.Sound('WeaponHoming.wav')

face = cv2.CascadeClassifier('haar cascade files\haarcascade_frontalface_alt.xml')
leye = cv2.CascadeClassifier('haar cascade files\haarcascade_lefteye_2splits.xml')
reye = cv2.CascadeClassifier('haar cascade files\haarcascade_righteye_2splits.xml')

lbl=['Close','Open']

model = load_model('models/cnncat2.h5')
path = os.getcwd()
cap = cv2.VideoCapture(0)
font = cv2.FONT_HERSHEY_COMPLEX_SMALL
count=0
SCORE_SET_POINT = 15
score=0
thicc=2
rpred=[99]
lpred=[99]
Dro_Second_Time = 0
Dro_First_Time = 0

####################### Car Control ##########################
car_speed = 0
car_st = 0
car_dir = 0
START_SPEED = 70
##############################################################
client = paho.Client()
# client.on_publish = on_publish
client.connect('broker.mqttdashboard.com', 1883)
client.loop_start()
# with keyboard.Listener(on_release=on_key_release) as listener:
#     ##slistener.join()
#     listener.start()
listener = keyboard.Listener(on_press=on_key_release)
listener.start()
##############################################################


while(True):
    ret, frame = cap.read()
    height,width = frame.shape[:2] 

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    
    faces = face.detectMultiScale(gray,minNeighbors=5,scaleFactor=1.1,minSize=(25,25))
    left_eye = leye.detectMultiScale(gray)
    right_eye =  reye.detectMultiScale(gray)

    cv2.rectangle(frame, (0,height-50) , (200,height) , (0,0,0) , thickness=cv2.FILLED )

    for (x,y,w,h) in faces:
        cv2.rectangle(frame, (x,y) , (x+w,y+h) , (100,100,100) , 1 )

    for (x,y,w,h) in right_eye:
        r_eye=frame[y:y+h,x:x+w]
        count=count+1
        r_eye = cv2.cvtColor(r_eye,cv2.COLOR_BGR2GRAY)
        r_eye = cv2.resize(r_eye,(24,24))
        r_eye= r_eye/255
        r_eye=  r_eye.reshape(24,24,-1)
        r_eye = np.expand_dims(r_eye,axis=0)
        rpred = np.argmax(model.predict(r_eye), axis=-1)
        if(rpred[0]==1):
            lbl='Open'
        if(rpred[0]==0):
            lbl='Closed'
        break

    for (x,y,w,h) in left_eye:
        l_eye=frame[y:y+h,x:x+w]
        count=count+1
        l_eye = cv2.cvtColor(l_eye,cv2.COLOR_BGR2GRAY)  
        l_eye = cv2.resize(l_eye,(24,24))
        l_eye= l_eye/255
        l_eye=l_eye.reshape(24,24,-1)
        l_eye = np.expand_dims(l_eye,axis=0)
        lpred = np.argmax(model.predict(l_eye), axis=-1)
        if(lpred[0]==1):
            lbl='Open'   
        if(lpred[0]==0):
            lbl='Closed'
        break

    if((rpred[0] == 0) and (lpred[0] == 0)):
        score = score+1
        if score >= SCORE_SET_POINT:
            Drossniess_Flag = 1

        cv2.putText(frame,"Closed",(10,height-20), font, 1,(255,255,255),1,cv2.LINE_AA)
    # if(rpred[0]==1 or lpred[0]==1):
    else:
        score = 0
        Drossniess_Flag = 0
        cv2.putText(frame,"Open",(10,height-20), font, 1,(255,255,255),1,cv2.LINE_AA)

    Dro_Second_Time = time.time()
    if((Dro_Second_Time - Dro_First_Time) >= 1):
        Dro_First_Time = Dro_Second_Time
        send_massege_drow(Drossniess_Flag)
        if(Drossniess_Flag == 1):
            sound_1.play()

    Drossniess_Flag = 0
    if(score<0):
        score=score-1

    cv2.putText(frame,'Score:'+str(score),(100,height-20), font, 1,(255,255,255),1,cv2.LINE_AA)
    if(score >= SCORE_SET_POINT):
        #person is feeling sleepy so we beep the alarm
        cv2.imwrite(os.path.join(path,'image.jpg'),frame)


        ##try:
            ##sound.play()
            
        ##except:  # isplaying = False
        ##    pass
        if(thicc<16):
            thicc= thicc+2
        else:
            thicc=thicc-2
            if(thicc<2):
                thicc=2
        cv2.rectangle(frame,(0,0),(width,height),(0,0,255),thicc) 
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
