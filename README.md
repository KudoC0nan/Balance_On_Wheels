![](https://i.imgur.com/V6Vat3e.jpg)

# <ins>Table of Contents

* [About the Project](#about-the-project)
  * [Tech Stack](#tech-stack)
  * [File Structure](#file-structure)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installations](#installations)
  * [Execution](#execution)
* [Theory and Approach](#theory-and-approach)
* [Results and Demo](#results-and-demo)
* [Future Work](#future-work)
* [Troubleshooting](#troubleshooting)
* [Contributors](#contributors)
* [Acknowledgements and Resources](#acknowledgements-and-resources)
* [License](#license)

---

# <ins>About the Project

**Modeling and Control of Two-Legged Wheeled Robot: In this project, we will be building a two wheeled robot (with a hip and knee joint) which can balance at variable heights including a provision for jumping.**

---

## <ins>Tech Stack

* <font color="red">C</font>
* <font color="red">Python</font>
* <font color="red">SolidWorks</font>
* <font color="red">ESP-IDF</font>
* <font color="red">AutoCad</font>
* <font color="red">Creality</font>

## <ins>File Structure
```
 ┣ CAD Designs                          
 ┃ ┣ Final Design for Laser Cut (3mm)                      
 ┃ ┣ Design For Laser Cut (5mm)           
 ┃ ┣ Intermediate Design              
 ┃ ┣ Prototype 2            
 ┃ ┗ Prototype                  
 ┃  
 ┣ Examples                      
 ┃ ┣ Jump Code
 ┃ ┣ Mpu Readings Code
 ┃ ┣ Mpu Readings and Servo Rotation Code
 ┃ ┣ Printing Info on terminal using Wifi Code                     
 ┃ ┣ Self Balancing Code
 ┃ ┣ Self Balance Servo set zero Code
 ┃ ┣ Variable Height Code
 ┃ ┗ OLED Code
 ┃
 ┣ Assets                          
 ┃
 ┣ Notes
 ┃  ┣ Arsh Notes
 ┃  ┗ Shreyas Notes  
 ┃
 ┣ Model 
 ┃ ┣ calculation_of_parameters.py
 ┃ ┣ calculation_of_angle_from_parameters.py
 ┃ ┗ graph.ipynb
 ┃
 ┣ Components
 ┃ ┣ sra-board-component
 ┃ ┗ rosserial_esp32 
 ┃ 
 ┣ firmware                               
 ┃ ┗ Self_Balancing_Servo_Lock_Jumping
 ┃   ┣ components
 ┃   ┃ ┣ include
 ┃   ┃ ┃ ┣ websocket_server.h
 ┃   ┃ ┃ ┗  websocket.h
 ┃   ┃ ┣ CMakeLists.txt  
 ┃   ┃ ┣ Kconfig
 ┃   ┃ ┣ websocket_server.c
 ┃   ┃ ┗ websocket.c     
 ┃   ┣ frontend
 ┃   ┃ ┗ index.html
 ┃   ┣ main 
 ┃   ┃ ┣ include
 ┃   ┃ ┃ ┣ tuning_websocket_server.h
 ┃   ┃ ┃ ┗ wifi_handler.h
 ┃   ┃ ┣ CMakeLists.txt  
 ┃   ┃ ┣ Kconfig
 ┃   ┃ ┣ self_balancing.c 
 ┃   ┃ ┣ servo_set.c
 ┃   ┃ ┣ jump.c
 ┃   ┃ ┣ tuning_websocket_server.c
 ┃   ┃ ┗ wifi_handler.c
 ┃   ┣ CMakeLists.txt
 ┃   ┗ sdkconfig
 ┗ README.md
```
---
# <ins>Getting Started

## <ins>Prerequisites

1. Used [Solidworks 2022](https://www.solidworks.com/) for Designing our Robot.

2. Used [Creality](https://www.creality.com/pages/download) Software used for 3D Printing

3. Used [ESP-IDF v4.4](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/) for building and flashing the code on ESP-32 Microcontroller.

4. Used [Python](https://www.python.org/) Scripts for calculation of specifications of Bot.

5. Used [Matplotlib](https://matplotlib.org/) for plotting the graphs.

## <ins>Installations

1. Clone the Repository 
    
  ```git clone git@github.com:KudoC0nan/Balance_On_Wheels.git```

2. Install ESP-IDF on your System
    
    [For Windows](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html#get-started-windows-first-steps)
    
    [For Linux and MacOS](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-macos-setup.html)

## <ins>Execution

1. Open ESP-IDF Terminal on Windows or Terminal on Linux

2. Run get_idf in Linux.

3. Goto The Repository 
    
   ```cd Balance_On_Wheels```

4. Goto firmware folder
 
   ```cd firmware```

5. Goto Self Balancing Code at Minimum Height
    
   ```cd Self_Balancing_Servo_Lock_Jumping```

6. Run Command for Building the Code
   
    ```idf.py build ```

7. Run Command for Opening the Configurations Tab to Setup the WIFI.
 
    ```idf.py menuconfig```
 
  When running the above command it will open a Configurations tab.
 
  Then select ```Component Config``` option.
 
  Then search for ```Wall-E Configurations``` and select this option.
 
  Then select ```Wifi Config``` option.
 
8. Run Command on Flashing the Code on our Bot.
    
    ```idf.py flash monitor```
 
---
# <ins>Theory And Approach

## <ins>Design 
* **Our First Approach was to design our robot on <font color="green">Solidworks</font>.**

    We designed a Bi-Pedal BOT on the <font color="red">Pantograph Mechanism</font>, which is a mechanical linkage connected in a manner based on parallelograms. 

    The Kinematics of the Bot were Derived for Pentograph design from which the key parameters such as the length of the linkages were able to be modified and optimized during the design process.

    The Hip Joint is defined to rotate in a 180 degree arc which results in the legs moving between Parallel and Anti-Parallel configurations. The angle between the vertical and the legs is shown for both the parallel and anti-parallel configurations and defined as the angles $\phi$ 1 and $\phi$ 2 as shown in Figure.
    The trapezoid which represents the body of the robot.

    ![](https://i.imgur.com/hQBeLkl.png)

    In the above Figure Leg extension is defined as the variable L is the vertical distance between the axis of the hip joints and the foot joint. The leg is shown at minimum extension Lmin the anti-parallel configuration and at maximal extension Lmax in the parallel configuration.

    ![](https://i.imgur.com/lHossMi.png)

    The above figure shown when the bot is at an arbitary position. Here,

    <font color="green">
    L1 ---> Length of Upper Leg Segment (From Hip Joint to Knee Joint)

    L2 ---> Length of Lower Leg Segment (From Knee Joint to Foot Joint)

    L3 --> Length from the Hip joint to the Mechanism's axis of Symmetry.
    </font>

* **Equations Used To Derive the System Design Variables**

    ![](https://i.imgur.com/E1Gui6i.png)
    ![](https://i.imgur.com/1IjtgOg.png)

    In Above Image we have equations to calculate the <font color="yellow"> $\phi$ 1, $\phi$ 2, L1, L2 and L3 </font>.
    Also In above Image at end , it is the General Equation of Length (vertical distance between the axis of the hip joints and the foot joint) which was used to plot the graph between the leg extension vs change in driver motor angle which is given below.
 Here, G (Gear Ratio) which is taken to be 1 for our Bot.
    
    
    ![](https://i.imgur.com/9046wKp.png)

    The above Graph gives is about change of Leg Extension wrt change in Driver Motor Angle. In the middle, the slope is large.
This means that small changes in motor angle cause a large amount of leg extension. 


    [Link To Python Script Used](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/model/calculation_of_angle_from_parameters.py)
 
    [LInk to Python Script to Plot the Graph](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/model/graph.ipynb)
 
 * **CAD Design**
  
    CAD design consist of 3D modeling of Bot design. We needed to check if various other aspects of systems and mechanical design satisfy our requiements. So CAD design form a very important part of our project.

   * **Parts Description**
     | Parts | Description |
     | ----- | ----------- |
     | ![](https://i.imgur.com/ZOTa2Wh.png)  | Base plate: Dimensions - 95mm x 107mm and thickness 3mm. Houses the PCB, Servos, MPU and Buck converter            |
     | ![](https://i.imgur.com/t7GqpoK.png)  | Leg L1: Dimensions - 45mm length and 3mm thickness            |
     | ![](https://i.imgur.com/W3yFh9P.png)  | Leg L2: Dimensions - 90mm length and 3mm thickness |
     | ![](https://i.imgur.com/B8XtYfe.png)  | Leg 2 Extended: 11mm length and 3mm thickness with 2.5mm x 10mm cut for N20 mount            |
     | ![](https://i.imgur.com/W01akd4.png)  | N20 Mount: Dimensions 15mm x 2.5mm x 10mm. It is the mount on the leg for N20 motor .             |
     | ![](https://i.imgur.com/v7RUtJc.png)  | Servo Mount: Servo mount for mounting them on th base plate.            |
     | ![](https://i.imgur.com/iP4s0lE.png)  | N20 Motor shaft extension: Dimensions - 1cm length and 3mm hole for N20 shaft to be fixed            |
     | ![](https://i.imgur.com/T8SLCjI.png)  | It is used as an extension for L1 to extrude it outwards in so that the legs can overlap. Dimensions: 20mm diameter and thickness 3mm            |

   * **CAD Model of Bot**

      ![](https://i.imgur.com/ttT9KF5.jpg) 


* **Specfications of Bot**
    <font color="red">
     
    ![](https://media.discordapp.net/attachments/1006252475629711551/1026960303247863980/WhatsApp_Image_2022-10-05_at_02.19.301.jpeg?width=343&height=458)
     
    ![](https://media.discordapp.net/attachments/1006252475629711551/1026960303486931045/WhatsApp_Image_2022-10-05_at_02.19.30.jpeg?width=343&height=458)
    
    Lmax = 13 cm

    Lmin = 4 cm
     
    $\phi$ 1 = $45{\textdegree}$

    $\phi$ 2 = $15{\textdegree}$

    </font>


## <ins> Components
* Bot Parts of Acrylic Material (Laser-Cutted)
* N20 motor Shaft for Wheels (3D Printed)
* SRA PCB 
* N20 motors 
* MG90 Servo Motors (Connected to all Hip joint)
* Buck Converter (LM2596) (Regulates 12v to 5v for SRA PCB and 12v to 6v for N20 Motors)
* Bearings
* Shafts

> :memo: **Note:** [SRA Board Components](https://github.com/KudoC0nan/Balance_On_Wheels/blob/dev_arsh/Notes/Components.md)
 
> :memo: **Note:** [N20 Motors](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Shreyas%20Notes/N20_Motor.md)
 
> :memo: **Note:** [Mg90 Servo Motors](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Shreyas%20Notes/Servo_Motor.md)
 
## <ins> PID
A PID controller is one kind of device used to control different process variables like pressure, flow, temperature, and speed in industrial applications.
 
![](https://miro.medium.com/max/1400/1*K_yaMyOkUNJzBpjutSmpwQ.png) 

PID stands for Proportional,Derivative and Integral controller. It is used in our Project for Self Balncing the bot.
 
For self balancing our bot should be able to minimize pitch error ,i.e, difference between current pitch angle to the initial angle of reference (Set point). 

 In self balancing P-Term reduces the pitch error, but this correction leads to instability and oscillations.
 
 To prevent the oscillations of the bot along the setpoint, we use D-Term, which tries to flatten the error trajectory in horizontal line which it achieves 
 achieves by damping the force of P term which prevents overshooting the setpoint
 
 Sometimes applied Force is not enough to bring the error to zero (bot is in steady state),to correct this error, we use I-term, which will increase    
 force as the time passes and will correct the steady state error. 

 > :memo: **Note:** [More on PID Explanation](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Arsh%20Notes/PID%20Explanation)

## <ins> Code Phase

* Here, we First wrote the algorithm for Self-Balancing  using the PID controller for the bot.

  For self-balancing the bot, we need to keep the bot a bit above our desired angle (Setpoint), since the bot is very fast and will fall down once it's past the desired angle.

  The pitch angle is required for Self-Balancing which is obtained from the Inertial Measurement Unit(IMU sensor) plug-in.

  > :memo: **Note:**[Link to Explanation of Self Balancing Code](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Arsh%20Notes/Self%20Balancing%20Code.md)

* After Successful Run of Self Balancing Code, we than wrote the code for Servo moving from Maximum to Minimum Length (Variable Height).

  [Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Variable_Height_Code)

* After that we wrote the code of integrating Self Balancing Code with servos locking up at minimum height for Self Balancing of Bot at Minimum Height.
PID is used for balancing along with servo set zero which servos lock the bot in minimum height simultaneously so that the bot can remain stable at that position or otherwise the bot may collapse. Also before Balancing the bot we set servo zero first and then the self balancing code starts to function.

  [Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Self_Balance_Servo_SetZero)

  **Flow Chart of Code**
  
   ![](https://i.imgur.com/n4e01mY.png)

* After Which we wrote the Jumping Code for Bot to Jump from Minimum Position.
  
  ![](https://camo.githubusercontent.com/c6bec6da97ed148470ad69aaec32fd8a89f65f68002f9bfc26a169f85f7a249e/68747470733a2f2f6d656469612e646973636f72646170702e6e65742f6174746163686d656e74732f313030363235323437353632393731313535312f313032333236383730363638353537313232352f494d475f32303232303932345f3231353335333537382e6a70673f77696474683d393630266865696768743d343533)
 
  Here, basically we are increasing the Height of the Robot in iterations rather than in a single movement. This is because, such movement with appropriate  delays produce a thrust which pushes the bot upwards. Such thrust is not produced is a single down-up movement.
 
  > :memo: **Note:**[Link to Explanation of Jump Code](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Shreyas%20Notes/Jump_code_explanation.md)
 
   [Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Jump_Code)

* After finally we wrote the code for integration of Jumping Code with Self Balancing Code.

  [Link to Code]()

---
## <ins>Results and Demo

* **OLED Demonstration**
 [![Oled Code](https://res.cloudinary.com/marcomontalbano/image/upload/v1665237564/video_to_markdown/images/video--bca3bd041dba9b3d700c9c021613d27f-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/AXOw94k.mp4 "Oled Code")
 
* **Bot moving from Min to Max Height**
  
  [![Servo movement from max height to min](https://res.cloudinary.com/marcomontalbano/image/upload/v1665227522/video_to_markdown/images/video--2fc68c8adef49d92d4c48957409f9845-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/x1DZ9R9.mp4 "Servo movement from max height to min") 


* **Bot given forward velocity when castor attached**
[![Forward Velocity with castor ](https://res.cloudinary.com/marcomontalbano/image/upload/v1665225392/video_to_markdown/images/video--21e8f079837b8e2fc0c235660fa8e0f3-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/HnTzFTZ.mp4 "Forward Velocity with castor ")

* **Self Balancing Code with servos locking up at minimum height**

  [![Self Balancing](https://res.cloudinary.com/marcomontalbano/image/upload/v1665223839/video_to_markdown/images/video--c4e503c35718a098a8a9aa508368f321-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/5cLTLLT.mp4 "Self Balancing")

* **Self Balancing Code with servos locking up at maximum height**

  [![Self Balancing at Max Height](https://res.cloudinary.com/marcomontalbano/image/upload/v1665224845/video_to_markdown/images/video--90b7d7dd7a19ac7ebda929b3f229c663-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/0afDTOF.mp4 "Self Balancing at Max Height")

* **Jumping of Robot**

  [![Video](https://res.cloudinary.com/marcomontalbano/image/upload/v1665222817/video_to_markdown/images/video--7fc84c42adbc8697c5772e110ad04cbf-c05b58ac6eb4c4700831b2b3070cd403.jpg)](https://i.imgur.com/9ucrqm1.mp4 "Video")

* **Self Balancing and Jumping Bot**  
--- 
## <ins>Future Work

1) Multi Terrain RoBot (changes length of legs based upon terrain and balance itself)
 
2) Implementing Positional control using LQR and roll stabilization.
 
3) Segway Bot (Assistant Type Robot)
    
   https://techcrunch.com/2016/01/07/segway-has-created-a-robot-that-connects-to-your-two-wheeled-scooter/

4) For obstacle avoiding (using Ultrasonic sensors or Lidar and Computer Vision) 
    
   https://www.science.gov/topicpages/o/obstacle+detection+algorithm

---

## <ins>Troubleshooting

1. Mounting of motors at wheel joint.
    
2. Gears, were removed from the design, considering much was lost due to the gear mechanism. Instead, MG90s servos were used.

3. Length of legs and distance from the AOS were reconsidered many times.

4. Base plate of the bot had some design flaws regarding placement of holes for servos and mpu.

5. No holes made in Base plate to for Castor Wheels (castor wheel used for experimental purposes like checking torque and rpm of motors in forward and backward direction) 

6. N20 heating up within few moments of testing. As we were giving 12V directly to 6V N20's they were heating up. We used a LM2596 buck converter to convert the 12V to 6V.

---

## <ins>Contributors

[Arsh Khan](https://github.com/Arsh-Khan)

[Shreyas Patil](https://github.com/KudoC0nan)

---

## <ins>Acknowledgements and Resources

Special Thanks to Our Mentors [Marck Koothoor](https://github.com/marck3131),[Ayush Kaura](https://github.com/Ayush-Kaura),[Priyal](https://github.com/Pixels123priyal)
for Mentoring and Guiding us in our project.

Special Thanks to [SRA VJTI](https://github.com/SRA-VJTI) for giving us the chance to do the project.

**Resources**
1. [ESP-IDF Docs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)

2. [SOLIDWORKS Playlist](https://www.youtube.com/playlist?list=PLrOFa8sDv6jcp8E3ayUFZ4iNI8uuPjXHe)

3. [Reserach Paper for Reference (MIT Paper of Balancing and Jumping of Mono Pedal Bot](https://dspace.mit.edu/handle/1721.1/119961)

4. [Research Paper for Reference (Czech Technical University)](https://wiki.control.fel.cvut.cz/mediawiki/images/9/92/Dp_2021_kollarcik_adam.pdf)

5. [Reference Paper for PID](https://www.wescottdesign.com/articles/pid/pidWithoutAPhd.pdf)

---
## License

[MIT Licence](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Documentation/LICENSE)
