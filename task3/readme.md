**Padestrian Button Physical Implementation on Arduino UNo hardware, LEDS, bbreadboard**

**task 1** 


https://github.com/user-attachments/assets/488c6cd0-a2a8-421c-9432-21d601aec542

In Task 1, I built a standard 3-light car traffic light using a 4-stateswitch-case state machine and non-blockingmillis() timers. It automatically cycles through Red (20s), Red + Yellow (3s), Green (20s), and Yellow (3s) in a continuous loop.

**task 2**

https://github.com/user-attachments/assets/df751ba1-5061-49e8-a7e6-13f511929e66

In Task 2, I added a pedestrian light and a button to the traffic light. Normally, cars have Green and pedestrians have Red. When someone presses the button, the Arduino waits until cars have had at least 10 seconds of Green, switches cars to Yellow for 5 seconds, and then turns Car Red and Pedestrian Green for 10 seconds so they can cross saffely. After that, it goes back to Red for everyone and restarts the cycle.



