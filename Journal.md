---
Title: "GLARE"
Author: "rrop"
Description: "AR Glasses for everyday assistance"
Created On: "2025-07-25"
*Total Time Spent: 63h*
---

# July 25th: Optics Research

Ok so I googles AR glasses optics mechanisms and figured out that three main optics systems are used. smtg known as waveguide, smtg called birdbath and then the good old prism(also called wavesplitter optics by some websites).
So basically for waveguide the have a projector like micro oled display which shoots light and the the guide it through inbuilt micro optics in the lens to get the hud. Buuuutttt :
  1. super expensive
  2. Not hackable/Diy able
  3. No clue wehere i could even get it
So waveguide is a no go. (ps its used in even realities G1)

<img width="861" height="447" alt="image" src="https://github.com/user-attachments/assets/79e7f1d9-5360-40a6-9682-f692e3def9eb" />

Then there is wavesplitter. So basically light from a micro oled is first collimated by a lens, and then passed through a special prism called beamsplitter, which makes it so that half the light entering the eye is from the display and other half from outside world. It works, and is pretty small, but the issue is it has a lot of imperfections and causes double images.
I did an optics sim on phydemo for this

<img width="1002" height="380" alt="image" src="https://github.com/user-attachments/assets/9cdb3b0e-012b-403e-97cd-18aa7a9cc67c" />

This is pretty simply optics so ill use either this or birdbath.

An example of birdbath is google glass explorer. It basically involves the same thing as the wabvesplitter, just tat light exiting prism is then focused by a semi transparent mirror onto the eye, along with a bit of light from outside world. This system reduces the imperfections by a lot, but is pretty bulky and tougher to get right.


<img width="563" alt="Screenshot 2025-05-23 at 10 08 52 PM" src="https://github.com/user-attachments/assets/a083e56a-e7a4-4376-aa7e-06108bcde340" />

SOOOO rn im super confused wut to do, i guess ill (as in make gpt ...) do some calc and figure out wut i want.
OKKKKK, so i did some mth (:P) and figured out that i can try for a birdbath and if worst case it doesnt work i can just reposition the beam splitter prism and the system will work as wavesplitter optics. Yippe
So ill try to do birdbath ig.

**Session time spent: 5h**

# July 26th: More Research

So now tat I decided on birdbath, I had to find decide on the display I was gonna use. So, I did some searching about micro oleds and found a good one for a good price on alibaba. It also came with the driver board so that was a plus.
Its the ET039XGM Micro OLED, and its 0.39".

SO now finally I could do some optics calcs.
Before that, I also made a rough simulation of birdbath on phydemo.

<img width="630" height="386" alt="image" src="https://github.com/user-attachments/assets/bb8dba2b-2528-4bd0-9180-9cc555690225" />

here the outside light wiuld enter through the spherical mirror, which is supposed to be semi transparent [I cant show tht on phydemo :( ]

So by estimation, using oled size, a 10x10x10mm beam splitter cube with a 45degree prism would suffice. Using this, and thin lens equation, i figured out tat the focal length of collimating lens shuld be 13-14mm, as thats distance bw display and prism. and then I can place the combiner just after the  prism. I also learned tat basically the combiner is almost flat, its slightly curevd. Its purpose is just to redirect light and include outside light. and as combiner is just after prism, its size has to be bigger than prism so it can effectively redirect light directed towards it. Sooo, ill be getting one of i guess a 20x20 size. 
I googles and yippe found a 22x20mm one. So basically i finally finished my optics, and will start my pcb tmrw.

**Session time spent: 4h**

# July 27th: PCB Time, or is it?

Soo for the pcb, I decided that I would be making an FGPA board of sorts. So like basically a full on computer that could linux and that would control everything else.
I decided I wanted a camera, google a bit and found that I liked the OV5640 AF. I also wanted a mic, gyro, gps and wifi nd bt capabilities. So I went on googling the components I could use.
I decided upon the RK3566. Its one of the newer rockchip socs. Also i wanted it to be small, so instead of using an SOM I decided to use the SOC and choose the other stuf myself.
For the RAM is choose IM8G32L4JCBG-046I which is a 1GB LPDDR4X. For flash, 128Mb of SPI NOR flash. Also a chip with 8gb emmc and for pmic an rk817-5.

BOM img:

<img width="1313" height="321" alt="image" src="https://github.com/user-attachments/assets/525ee377-7283-4fb7-bca5-4c1de95c1b58" />

This research took lik 5 hrs, as I had to find the libraries, datasheets and kicad footprints and symbols of each as well.

BUTT, As soon as I started on the schematic I realized smtg. THIS SHIT WAS WAYYYY TO COMPLEX. IT would take atleast 2 weeks and i dint hv tat much time :(
SOO I scrapped this idea altogether and spent like another hour thinkin wut to do/

SOOOO..... I GIT A GOOD IDEA.
Basically, ill use an esp 32 module as the core chip, and the peripherals will send data to it and stuf. Then itll communicate the data to a phone through its BT or wifi.
The phone will do all the processing.
ALSOOOOO, the hud driver board is HDMI. So i can directly control it through the phone through a usb c to micro hdmi cable. Another plus

SO i made a rough plan of wut I would need.
1. esp
2. usb to uart to progrma it
3. 2 lipo bats for power (3.7v 500mah)
4. a voltage regulator
5. ldo
6. voltage boost
7. smtg to measure battery %
8. peripherals (stuf lik cam, gps, switches etc)
9. smtg to charge lipo

ANNDDD I DID A SHIT TON of research and finally decided upon a good esp32 module ill use as core.
Its the ESP32-S3-WROOM-1U-N16R8
It has 16GB flash, 8GB PSRAM wifi bt and usb support for my camera

Ill do the rest of the bom tmrw

**Session time spent: 7h**

# July 28th: BOM + Schematic

Soo for the pcb, I wont get into the details. Like there isnt much to discuss particularly. I just spent a shit ton of time (5 hrs) looking at datasheets, chat gpting and googling a lot of shit and finally finished the BOM. (it took a lot of time as I was also simultaneously finding the footprints and symbols of the parts I was gonna use)

<img width="1545" height="528" alt="image" src="https://github.com/user-attachments/assets/4fa944ef-8c14-45bf-aa73-ffaa90d3cc2a" />

PS.. This diesbt have the otpics and lipo. Ill add those later.

ANYWS. FINALLY TIME TO START WITH THE SCHEMATIC
so i started with the power management part.

So i was gonna have a micro usb b port which would be both for programming and charging the lipos.

<img width="657" height="451" alt="image" src="https://github.com/user-attachments/assets/bdf85a59-a080-4c3a-a5f5-b230582e55ba" />

This was the schematic.
So the usb prot d+ and d- ill later connect to d+ and d- of usb to uart.
the fuse protect the charger from overcurrent.

The prog sets charge current. For ap5054, its equal to 1200/resistance bw prog and gnd. as im using 2 lipos in parallel, ill keep it as 2k ohm so that the batteries charge at 600mAh.
i.e. 0.6C which is good.

Now time for the voltage supervisor to prevernt the lipos from burning out. : p

<img width="678" height="578" alt="image" src="https://github.com/user-attachments/assets/23326c25-9a40-441d-8211-f6d2e6b3da07" />

here the vout will be connected to psen of the 5v boost to enable power saving.

Now time for power on/off and the 5v boost.

<img width="1448" height="697" alt="image" src="https://github.com/user-attachments/assets/b434a13a-0085-4fd7-96fb-1536db1fc94c" />

THIS SCHEMATIC TOOK WAYYYYYYY TOOOO LONG.

now for the easy part. the battery gauge and the ldo to convert 5v to 3.3v(esp and lots of components have 3.3v logic)

<img width="1388" height="590" alt="image" src="https://github.com/user-attachments/assets/4b049dc1-754f-49e4-bc14-d7eb9196d55e" />

this was pretty easy.

FINALLLYY, AFTER ALMOST THE ENTIRE DAY... THE POWER PART OF THE SCHEMATIC IS DONE

<img width="987" height="607" alt="image" src="https://github.com/user-attachments/assets/62b5d8de-ba75-41c0-9e15-9365d1fd0e5b" />

**Session time spent: 13h**

# July 29th: Schematic 2

Time for the components part of the schematic

USB TO UART: DONE

<img width="430" height="512" alt="image" src="https://github.com/user-attachments/assets/2e1fbf0c-ea52-4565-bcb2-4e1a3c9a6a53" />

Now i addes some transistors to the esp reset button and for the boot mode gpio. Ive connected them to the usb to uart dtr and rts.

<img width="496" height="520" alt="image" src="https://github.com/user-attachments/assets/c87d5dc6-e1bb-4149-a130-13486f4831c8" />

DONE

Now the gyro:

<img width="597" height="536" alt="image" src="https://github.com/user-attachments/assets/e10af5b7-cca4-468a-b049-ddbc1abd2368" />

now the gps:

<img width="875" height="387" alt="image" src="https://github.com/user-attachments/assets/7bd8e1ee-0644-45ad-ad5a-a4703c751cac" />

Right I also added a gpio to control the state of the reset pin, so incase the gps misfires or gives wrong data, i can reset it through code.

Now the mics:

<img width="795" height="617" alt="image" src="https://github.com/user-attachments/assets/ac338a0b-5e93-4504-9473-c7cf7eb5bd99" />

Now the hud: for the hud also i added a gpio to control wether its on or off.

<img width="671" height="606" alt="image" src="https://github.com/user-attachments/assets/07d0af44-bf16-4388-a82b-14a2de1d4b54" />

The camera:

<img width="456" height="422" alt="image" src="https://github.com/user-attachments/assets/9fe08e38-0914-44dd-bbb0-843dcf48e960" />

the led:

<img width="401" height="335" alt="image" src="https://github.com/user-attachments/assets/66b5193c-9fbc-48f7-83f8-ac028a572f99" />

right i just remembered. I might have forgotten to mention this before, but i added a red led to the charging path, so that when the lipos are charging, you can visually tell

and a touch reset user switch:

<img width="567" height="385" alt="image" src="https://github.com/user-attachments/assets/1e31f9d6-4303-4662-91b9-ac97ee3c55f3" />

and finally, after going through the datasheets a million times:
the esp:

<img width="716" height="667" alt="image" src="https://github.com/user-attachments/assets/3c7630f1-a04e-4933-b68e-87598d496d13" />

There isnt much to say or explain about this, it was just adding and connecting the parts. But it still took me the entire day basically
The schematic is officially done, and Ill start routing

**Session time spent: 12h**

# July 30th: Routing

There isn't much to say abt this part. 
I just imported the parts from the schematic and spent a shit ton of time routing amd positioning everything.
I started with the usb, i2s and i2c. Then the serial and uart, then the gpio and then power.
The pwoer traces were pretty thick and others were default size pretty much.
Its a 4 layer pcb so I can make it small and stuf.

So basically I finished routing almost everything except the +5v, vbus and stuf. Will do tat tmrw

**Session time spent: 12h**

# July 31th: Finishing Routing, CAD and Firmware

Ok so I spent lik 2 hrs and finished the routing.

<img width="1245" height="467" alt="image" src="https://github.com/user-attachments/assets/8f83443b-cc58-4277-a3ca-ec69367ea9e2" />


Now time for cad

For this I spent like 15 mins and found a step model of glasses. I imported that into my cad. Then i deleted their arms and modeled them based on my battery and pcb in such a way the the weight shuld be on my ears, hopefully. I also modeled the hud after this.

Overall, this entire modelling took me abt 4 hrs.

<img width="816" height="605" alt="image" src="https://github.com/user-attachments/assets/bc4a59b2-c61f-47b2-9ce7-d1077db5b98e" />


Now time for the firmware.
For the firmware, I decided to use platformio, so tat later on interfacing would be easier and testing and dev would also be pretty easy.

SOOO, I created projected and luckily found a board verryy close to mine. The only diff was tat mine has 16Mb flash while this board has 8Mb.
But i dont think while programming it would make much difference.

Anyws, I organised stuf into folders. Figured out how platformio works a little more (2nd time using it)
and wrote up basic code for all the components.

So i googled and figured out that its better to add stuf in a folder called include so tat those files dont get called multiple times (I hv no clue wut this means, just tat multiple people online suggested it so ill do it : P )

Anyws, finalllYY FIRMWARE DONE AND EVERYTHING DONE.... FOR now.. YIPPEEEEE : )

**Session time spent: 10h**

**Total Time Spent: 62h**

# August 2nd: FREE
Guys,, today I was free sooo I optimized BOM a bit and managed to bring down total price from 310$ to max 289$ (most probably less) Basically I was getting ripped of for pcb by seed studio. JLC is much cheaper.
That was the main change IG.

**Session time spent: 1h**

**Total Time Spent: 63h**
