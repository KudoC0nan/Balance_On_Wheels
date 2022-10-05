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
- myProject/
             - CMakeLists.txt
             - sdkconfig
             - components/ - component1/ - CMakeLists.txt
                                         - Kconfig
                                         - src1.c
                           - component2/ - CMakeLists.txt
                                         - Kconfig
                                         - src1.c
                                         - include/ - component2.h
             - main/       - CMakeLists.txt
                           - src1.c
                           - src2.c

             - build/
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

4. Goto Self Balancing Code at Minimum Height
    
   ```cd Self_Balancing_Servo_set_zero```

5. Run Command for Building the Code
   
  ```idf.py build ```

6. Run Command for Opening the Configurations Tab to Setup the WIFI.
 
  ```idf.py menuconfig```
 
  When running the above command it will open a Configurations tab.
 
  Then select ```Component Config``` option.
 
  Then search for ```Wall-E Configurations``` and select this option.
 
  Then select ```Wifi Config``` option.
 
  ![](https://i.imgur.com/qOl60Gn.png)
 
  Then enter your Wifi ssid and password and press button S to Save the Current Wifi Configuraton.
 
  Press Button Q to exit the Configurations Tab
 
7. Run Command on Flashing the Code on our Bot.
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

    The above figure shown when the bot is at an arbitary position.
    L1,L2,L3 are the length of linkages (System design parameters / variables).

    <font color="green">
    L1 ---> Length of Upper Leg Segment (From Hip Joint to Knee Joint)

    L2 ---> Length of Lower Leg Segment (From Knee Joint to Foot Joint)

    L3 --> Length from the Hip joint to the Mechanism's axis of Symmetry.
    </font>

* **Equations Used To Derive the System Design Variables**

    ![](https://i.imgur.com/E1Gui6i.png)

    In Above Image we have equations to calculate the <font color="yellow"> $\phi$ 1, $\phi$ 2, L1, L2 and L3 </font>.

    ![](https://i.imgur.com/1IjtgOg.png)

    In above Image, it is the General Equation of Length (vertical distance between the axis of the hip joints and the foot joint)
    Here, G (Gear Ratio) which is taken to be 1 for our Bot.
    
    
    ![](https://i.imgur.com/9046wKp.png)

    The above Graph gives is about change of Leg Extension wrt change in Driver Motor Angle. 


    [Link To Python Script Used](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/model/calculation_of_angle_from_parameters.py)
    [LInk to Python Script to Plot the Graph](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/model/graph.ipynb)

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

PID stands for Proportional,Derivative and Integral controller. It is used in our Project for Self Balncing the bot.
 
For self balancing our bot should be able to minimize pitch error ,i.e, difference between current pitch angle to the initial angle of reference (Set point). 

 In self balancing P-Term reduces the pitch error, but this correction leads to instability and oscillations.
 
 To prevent the oscillations of the bot along the setpoint, we use D-Term, which tries to flatten the error trajectory in horizontal line which it achieves 
 achieves by damping the force of P term which prevents overshooting the setpoint
 
 Sometimes applied Force is not enough to bring the error to zero (bot is in steady state),to correct this error, we use I-term, which will increase    
 force as the time passes and will correct the steady state error. 

 > :memo: **Note:** [More on PID Explanation](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Arsh%20Notes/PID%20Explanation)

## <ins> Code Flow

Here, we First wrote the algorithm for Self-Balancing using the PID controller for the bot.

For self-balancing the bot, we need to keep the bot a bit above our desired angle (Setpoint), since the bot is very fast and will fall down once it's past the desired angle.

The pitch angle is required for Self-Balancing which is obtained from the Inertial Measurement Unit(IMU sensor) plug-in.

> :memo: **Note:**[Link to Explanation of Self Balancing Code](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Develop/Notes/Arsh%20Notes/Self%20Balancing%20Code.md)

And after Successful Run of Self Balancing Code, we than wrote the code for Servo moving from Maximum to Minimum Length (Variable Height).

[Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Variable_Height_Code)

And after that we wrote the code of integrating Self Balancing Code with servos locking up at minimum height for Self Balancing of Bot at Minimum Height.
PID is used for balancing along with servo set zero which servos lock the bot in minimum height simultaneously so that the bot can remain stable at that position or otherwise the bot may collapse. Also before Balancing the bot we set servo zero first and then the self balancing code starts to function.

[Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Self_Balance_Servo_SetZero)

**Flow Chart of Code**
![](https://i.imgur.com/6f7omtf.png)

After Which we wrote the Jumping Code for Bot to Jump from Minimum Position.

[Link to Code](https://github.com/KudoC0nan/Balance_On_Wheels/tree/Develop/Examples/Jump_Code)

After Which we wrote the code for integration of Jumping Code with Self Balancing Code.

[Link to Code]()

---
## <ins>Results and Demo

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

4. [Reference Paper for PID](https://www.wescottdesign.com/articles/pid/pidWithoutAPhd.pdf)

---
## License

[MIT Licence](https://github.com/KudoC0nan/Balance_On_Wheels/blob/Documentation/LICENSE)
