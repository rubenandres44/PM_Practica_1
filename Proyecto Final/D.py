#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
import math
import time
from std_srvs.srv import Empty

x1 = 0
y1 = 0
theta1 = 0

x2 = 0
y2 = 0
theta2 = 0

x3 = 0
y3 = 0
theta3 = 0

x = 0
y = 0
theta = 0

x5 = 0
y5 = 0
theta5 = 0

x6 = 0
y6 = 0
theta6 = 0

def poseCallback1(pose_message):
    global x1
    global y1
    global theta1
    
    x1 = pose_message.x
    y1 = pose_message.y
    theta1 = pose_message.theta

def poseCallback2(pose_message):
    global x2
    global y2
    global theta2
    
    x2 = pose_message.x
    y2 = pose_message.y
    theta2 = pose_message.theta

def poseCallback3(pose_message):
    global x3
    global y3
    global theta3
    
    x3 = pose_message.x
    y3 = pose_message.y
    theta3 = pose_message.theta
    
def poseCallback4(pose_message):
    global x
    global y
    global theta
    
    x = pose_message.x
    y = pose_message.y
    theta = pose_message.theta

def poseCallback5(pose_message):
    global x5
    global y5
    global theta5
    
    x5 = pose_message.x
    y5 = pose_message.y
    theta5 = pose_message.theta

def poseCallback6(pose_message):
    global x6
    global y6
    global theta6
    
    x6 = pose_message.x
    y6 = pose_message.y
    theta6 = pose_message.theta

def orientate (xgoal, ygoal):
    global x 
    global y
    global theta

    velocity_message = Twist()
    cmd_vel_topic = '/turtle4/cmd_vel'

    while(True):
        ka = 4.0
	if (xgoal-x == 0 and ygoal-y < 0):
       		desired_angle_goal = -(math.pi/2)-.01
        if (xgoal-x == 0 and ygoal-y > 0):
		desired_angle_goal = (math.pi/2)+.01
	#if (ygoal-y == 0 and xgoal - x == 0):
       	#	desired_angle_goal = -math.pi/2
	else:
		desired_angle_goal = math.atan2(ygoal-y,xgoal-x)
	dtheta = desired_angle_goal-theta        
	angular_speed = ka * (dtheta)

        velocity_message.linear.x = 0.0
        velocity_message.angular.z = angular_speed
        velocity_publisher.publish(velocity_message)
        #print ('x=', x, 'y=', y)

        if (dtheta < 0.01):
            break

def go_to_goal (xgoal, ygoal):
    global x
    global y
    global theta

    velocity_message = Twist()
    cmd_vel_topic = '/turtle4/cmd_vel'

    while(True):
        kv = 1.0				
        distance = abs(math.sqrt(((xgoal-x)**2)+((ygoal-y)**2)))
        linear_speed = kv * distance

        ka = 4.0
	if (xgoal-x == 0 and ygoal-y < 0):
       		desired_angle_goal = -(math.pi/2)-.01
        if (xgoal-x == 0 and ygoal-y > 0):
		desired_angle_goal = (math.pi/2)+.01
	#if (ygoal-y == 0 and xgoal - x == 0):
       	#	desired_angle_goal = -math.pi/2
	else:
		desired_angle_goal = math.atan2(ygoal-y,xgoal-x)
	dtheta = desired_angle_goal-theta        
	angular_speed = ka * (dtheta)

        velocity_message.linear.x = linear_speed
        velocity_message.angular.z = angular_speed
        velocity_publisher.publish(velocity_message)
        #print ('x=', x, 'y=', y)

        if (distance < 0.01):
            break

def encontrarCamino(xg,yg):
    global x1
    global y1
    global x2
    global y2
    global x3
    global y3
    global x
    global y
    global x5
    global y5
    global x6
    global y6
    
    distance_to_1=abs(math.sqrt(((x1-x)**2)+((y1-y)**2)))
    distance_to_2=abs(math.sqrt(((x2-x)**2)+((y2-y)**2)))
    distance_to_3=abs(math.sqrt(((x3-x)**2)+((y3-y)**2)))
    distance_to_5=abs(math.sqrt(((x5-x)**2)+((y5-y)**2)))
    distance_to_6=abs(math.sqrt(((x6-x)**2)+((y6-y)**2)))

    time.sleep(0.5)

    lista=[distance_to_1,distance_to_2,distance_to_3,
           distance_to_5,distance_to_6]
    
    pos=lista.index(min(lista)) + 1
    
    if(pos==1):
        tomaCamino(x1,y1,xg,yg,distance_to_1)
    elif(pos==2):
        tomaCamino(x2,y2,xg,yg,distance_to_2)
    elif(pos==3):
        tomaCamino(x3,y3,xg,yg,distance_to_3)
    elif(pos==4):
        tomaCamino(x5,y5,xg,yg,distance_to_5)
    else:
        tomaCamino(x6,y6,xg,yg,distance_to_6)

def tomaCamino (xn,yn,xg,yg,distance):
	global x
	global y
	
	xa=0
	ya=0

	if(distance > 0.5):
		if(0.01>abs(xg-x)):
			time.sleep(0.5)
			orientate(xg,yg)
			time.sleep(0.5)
			go_to_goal(xg,yg)
		elif(xg>x and yg>y):
			xa=x+0.5
			ya=y+0.5
			time.sleep(0.5)
			orientate(xa,ya)
			time.sleep(0.5)
			go_to_goal(xa,ya)
		elif(xg>x and yg<y):
			xa=x+0.5
			ya=y-0.5
			time.sleep(0.5)
			orientate(xa,ya)
			time.sleep(0.5)
			go_to_goal(xa,ya)
		elif(xg<x and yg>y):
			xa=x-0.5
			ya=y+0.5
			time.sleep(0.5)
			orientate(xa,ya)
			time.sleep(0.5)
			go_to_goal(xa,ya)
		else:
			xa=x-0.5
			ya=y-0.5
			time.sleep(0.5)
			orientate(xa,ya)
			time.sleep(0.5)
			go_to_goal(xa,ya)
		#time.sleep(0.5)
		#orientate(xg,yg)
		#time.sleep(0.5)
		#go_to_goal(xg,yg)
	elif(xn>x):
		xa = x - 0.5
		if(yn>y):
			ya=y-0.5
		else:
			ya=y+0.5
		time.sleep(0.5)
		orientate(xa,ya)
		time.sleep(0.5)
		go_to_goal(xa,ya)
		
		#time.sleep(0.5)
		#orientate(xa,y)
		#time.sleep(0.5)
		#go_to_goal(xa,y)
	else:#elif(xn<x):
		xa = x + 0.5
		if(yn>y):
			ya=y-0.5
		else:
			ya=y+0.5
		time.sleep(0.5)
		orientate(xa,ya)
		time.sleep(0.5)
		go_to_goal(xa,ya)

		#time.sleep(0.5)
		#orientate(xa,y)
		#time.sleep(0.5)
		#go_to_goal(xa,y)
	#""""
	#elif(yn>y):
	#	ya = y - 0.5
	 #       time.sleep(0.5)
	#	orientate(x,ya)
	#	time.sleep(0.5)
	#	go_to_goal(x,ya)
	#else:
	#	ya = y + 0.5
        #	time.sleep(0.5)
	#	orientate(x,ya)
	#	time.sleep(0.5)
	#	go_to_goal(x,ya)                
	#""""
	

if __name__ == '__main__':
    try:

        rospy.init_node('turtlesim_motion_pose', anonymous = True)

        cmd_vel_topic = '/turtle4/cmd_vel'
        velocity_publisher = rospy.Publisher(cmd_vel_topic, Twist, queue_size = 10)
	
        position_topic_1 = '/turtle1/pose'
        pose_subscriber_1 = rospy.Subscriber(position_topic_1, Pose, poseCallback1)
        time.sleep(1.0)   

    	position_topic_2 = '/turtle2/pose'
        pose_subscriber_2 = rospy.Subscriber(position_topic_2, Pose, poseCallback2)
        time.sleep(1.0) 
        
        position_topic_3 = '/turtle3/pose'
        pose_subscriber_3 = rospy.Subscriber(position_topic_3, Pose, poseCallback3)
        time.sleep(1.0)
        
        position_topic_4 = '/turtle4/pose'
        pose_subscriber_4 = rospy.Subscriber(position_topic_4, Pose, poseCallback4)
        time.sleep(1.0)
        
        position_topic_5 = '/turtle5/pose'
        pose_subscriber_5 = rospy.Subscriber(position_topic_5, Pose, poseCallback5)
        time.sleep(1.0)
        
        position_topic_6 = '/turtle6/pose'
        pose_subscriber_6 = rospy.Subscriber(position_topic_6, Pose, poseCallback6)
        time.sleep(1.0)

        global x
        global y

        xg=1.0
        yg=10.0
    	while (abs(x-xg)>0.001 and abs(y-yg)>0.001):
		time.sleep(0.5)
    		encontrarCamino(xg,yg)
		#print ('x=', x, 'y=', y)
            
        xg=2.5
        yg=1.0
    	while (abs(x-xg)>0.001 and abs(y-yg)>0.001):
		time.sleep(0.5)
    		encontrarCamino(xg,yg)
		#print ('x=', x, 'y=', y)
            
        xg=7.0
        yg=10.0
    	while (abs(x-xg)>0.001 and abs(y-yg)>0.001):
		time.sleep(0.5)
    		encontrarCamino(xg,yg)
		#print ('x=', x, 'y=', y)
		

    except rospy.ROSInterruptException:        
	pass
