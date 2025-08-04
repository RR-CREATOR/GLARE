# GLARE
Glasses Linked Augmented Reality Engine

**Description:**
GLARE is basically a glasses attachment. It has a custom pcb, which you could place either inside the frame of glasses if you 3d print the frame, or attach it outside. It has a custom HUD made using birdbath optics and a 0.39" display, on one side, so you aren't too disconnected with reality, and a lot of the issues causes by cheap optics are resolved through seperate vision. It features an esp32-s3-wroom-n16r8 motherboard which, along with a phone(to be added after testing pcb), will get data from 2 mics, a camera, a gyro and gps and give an Augmented Reality experience through the HUD, for assitance in day to day life.

**Why:**
I made this as I wanted to build something cool yet realistic, something I could carry around with me, and something which I could learn from building. I researched the optics and got a bit better at physics and learned how smart glasses optics work. At the same time, through designing the pcb, I got much better at. I learned a lot of new stuf, like adding planes, via stitching, impedance control and matching etc. PLUS I have always wanted my own smart glasses, and what better way to get them than building them yourself? This was overall a super fun and rewarding project, and I learned a lot about how various part and components interact with each other.
CAD:

<img width="1080" height="712" alt="image" src="https://github.com/user-attachments/assets/056dec02-db83-4b27-a8fe-3462d4bdb0dc" />


MainBoard and schematic:

<img width="1096" height="661" alt="image" src="https://github.com/user-attachments/assets/d5382a89-bc9a-4d37-a2ce-a789a15a96b2" />

<img width="1028" height="667" alt="image" src="https://github.com/user-attachments/assets/07e89a67-8f2b-46b6-a608-86a0e4fd6ffd" />

<img width="1232" height="460" alt="image" src="https://github.com/user-attachments/assets/40890bd4-f4a4-4c5f-b956-df0a410a5b4b" />

<img width="772" height="452" alt="image" src="https://github.com/user-attachments/assets/20b1a4eb-4056-4d67-a0c9-5a4f42d35397" />

<img width="1097" height="503" alt="image" src="https://github.com/user-attachments/assets/40c7c8df-8047-4372-be66-26ccc5f1e765" />

Ik it looks like a cheap cybertruck :/

BOM:

<table>
    <tr>
        <td>Category</td>
        <td>Component</td>
        <td>Part Number / Source</td>
        <td>Price (USD)</td>
        <td>Quantity</td>
        <td>Notes</td>
    </tr>
    <tr>
        <td>Core</td>
        <td>ESP32-S3-WROOM-1U-N16R8</td>
        <td>https://lcsc.com/product-detail/WiFi-Modules_ESPRESSIF-ESP32-S3-WROOM-1U-N16R8_C3013946.html?s_z=n_ESP32-S3-WROOM-1U-N16R8</td>
        <td>5.66</td>
        <td>1</td>
        <td>Core chip with wifi and bt</td>
    </tr>
    <tr>
        <td>Antenna</td>
        <td>Ezurio 001-0014</td>
        <td>https://www.digikey.com/en/products/detail/ezurio/001-0014/4732758</td>
        <td>3.41</td>
        <td>1</td>
        <td>2.4GHz for core</td>
    </tr>
    <tr>
        <td>Mosfet</td>
        <td>PMZ350UPEYL</td>
        <td>https://lcsc.com/product-detail/MOSFETs_Nexperia-PMZ350UPEYL_C478207.html?s_z=n_PMZ350UPEYL</td>
        <td>0.43</td>
        <td>10</td>
        <td>For display power switch</td>
    </tr>
    <tr>
        <td>USB to UART</td>
        <td>CH9102F</td>
        <td>https://lcsc.com/product-detail/USB-Converters_WCH-CH9102F_C2858418.html?s_z=n_CH9102F</td>
        <td>1.33</td>
        <td>1</td>
        <td>For Programming</td>
    </tr>
    <tr>
        <td>I�S Microphone</td>
        <td>SPH0645LM4H-B-8</td>
        <td>https://lcsc.com/product-detail/MEMS-Microphones_Knowles-SPH0645LM4H-B-8_C19190864.html?s_z=n_SPH0645LM4H-B</td>
        <td>8</td>
        <td>2</td>
        <td>MEMS microphone</td>
    </tr>
    <tr>
        <td>Transistors</td>
        <td>2SC4617R</td>
        <td>https://lcsc.com/product-detail/Bipolar-BJT_CBI-2SC4617R_C2836080.html?s_z=n_2SC4617R%2520BR</td>
        <td>0.35</td>
        <td>20</td>
        <td>Programming</td>
    </tr>
    <tr>
        <td>RGB LEDs</td>
        <td>WS2812B 2020</td>
        <td>https://lcsc.com/product-detail/RGB-LEDs-Built-in-IC_Worldsemi-WS2812B-2020_C965555.html?s_z=n_ws2812b%25202020</td>
        <td>0.41</td>
        <td>5</td>
        <td>For visual indication</td>
    </tr>
    <tr>
        <td>Micro USB B</td>
        <td>1050170001</td>
        <td>https://lcsc.com/product-detail/USB-Connectors_MOLEX-1050170001_C136000.html?s_z=n_C136000</td>
        <td>1.67</td>
        <td>1</td>
        <td>Charging LiPo</td>
    </tr>
    <tr>
        <td>Battery Charger</td>
        <td>AP5054HTCER</td>
        <td>https://lcsc.com/product-detail/Battery-Management_Wuxi-Chipown-Micro-electronics-AP5054HTCER_C2843820.html?s_z=n_ap5054htc</td>
        <td>0.15</td>
        <td>1</td>
        <td>Charging LiPo</td>
    </tr>
    <tr>
        <td>Low Voltage Detector</td>
        <td>XC61CC3002MR-G</td>
        <td>https://lcsc.com/product-detail/Supervisor-and-Reset-ICs_TOREX-XC61CC3002MR-G_C2456347.html?s_z=n_XC61CC3002MR</td>
        <td>0.92</td>
        <td>5</td>
        <td>Voltage Supervisor</td>
    </tr>
    <tr>
        <td>Battery Fuel Gauge</td>
        <td>MAX17048</td>
        <td>https://lcsc.com/product-detail/Battery-Management-ICs_Maxim-Integrated-MAX17048G-T10_C2682616.html</td>
        <td>4.16</td>
        <td>1</td>
        <td>Battery Percent</td>
    </tr>
    <tr>
        <td>Voltage Boost</td>
        <td>SY7088</td>
        <td>https://lcsc.com/product-detail/DC-DC-Converters_Silergy-SY7088DGC_C178240.html?s_z=n_SY7088</td>
        <td>1.52</td>
        <td>5</td>
        <td>Convert input to 5V</td>
    </tr>
    <tr>
        <td>LDO</td>
        <td>NCP167BMX330TBG</td>
        <td>https://lcsc.com/product-detail/Voltage-Regulators-Linear-Low-Drop-Out-LDO-Regulators_onsemi-NCP167BMX330TBG_C892227.html?s_z=n_NCP167BMX330TBG</td>
        <td>0.44</td>
        <td>1</td>
        <td>Convert 5V to 3.3V</td>
    </tr>
    <tr>
        <td>Schottky Diode</td>
        <td>RB160M-30</td>
        <td>https://lcsc.com/product-detail/Schottky-Diodes_High-Diode-RB160M-30_C2937163.html?s_z=n_C2937163</td>
        <td>0.38</td>
        <td>5</td>
        <td>Prevent back current in battery bypass</td>
    </tr>
    <tr>
        <td>Camera Module</td>
        <td>0V5640 160 AF</td>
        <td>https://www.aliexpress.com/item/3256806547258124.html?spm=a2g0o.productlist.main.7.3c04XpCAXpCAlF&amp;algo_pvid=1d8c60dc-197a-45e0-b911-5db3740a960b&amp;algo_exp_id=1d8c60dc-197a-45e0-b911-5db3740a960b-6&amp;pdp_ext_f=%7B%22order%22%3A%2248%22%2C%22eval%22%3A%221%22%7D&amp;pdp_npi=4%40dis%21USD%2125.14%216.32%21%21%21179.58%2145.16%21%40211b807017537824501694005e7310%2112000038123858641%21sea%21US%216130365553%21ABX&amp;curPageLogUid=NL6oj7jsGhIm&amp;utparam-url=scene%3Asearch%7Cquery_from%3A#nav-specification</td>
        <td>12.75</td>
        <td>1</td>
        <td>5MP autofocus camera</td>
    </tr>
    <tr>
        <td>Gyro + Accelo + Magneto</td>
        <td>ICM-20948</td>
        <td>https://lcsc.com/search?q=ICM-20948&amp;s_z=n_ICM-20948</td>
        <td>4.68</td>
        <td>1</td>
        <td>6-axis IMU</td>
    </tr>
    <tr>
        <td>GPS Module</td>
        <td>L86-M33</td>
        <td>https://www.mouser.in/ProductDetail/Quectel/L86-M33?qs=GedFDFLaBXFvEvNOo6IDYg%3D%3D</td>
        <td>12.82</td>
        <td>1</td>
        <td>Low-power GPS module</td>
    </tr>
    <tr>
        <td>Micro Oled Display</td>
        <td>ET039XGM OLED display + HDMI driver board</td>
        <td>Alibaba (including shipping) </td>
        <td>103</td>
        <td>1</td>
        <td>For HUD</td>
    </tr>
    <tr>
        <td>Mosfet main battery</td>
        <td>YJQD30P02A</td>
        <td>https://lcsc.com/product-detail/MOSFETs_YANGJIE-YJQD30P02A_C919546.html?s_z=n_C919546</td>
        <td>1.36</td>
        <td>5</td>
        <td>Mosfet for high power switching</td>
    </tr>
    <tr>
        <td>Mosfet main battery</td>
        <td>PMZ290UNE2YL</td>
        <td>https://lcsc.com/product-detail/MOSFETs_Nexperia-PMZ290UNE2YL_C478155.html?s_z=n_C478155</td>
        <td>0.53</td>
        <td>10</td>
        <td>Mosfet for high power switching</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>10k ohm</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0402J103-TS_C2906885.html?s_z=n_C2906885</td>
        <td>0.05</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>150ohm</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FOJAN-FRC0402F1500TS_C2909321.html?s_z=n_150ohm%2520resistor%25200402</td>
        <td>0.05</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>100k ohm</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0402JR-07100KL_C106234.html?s_z=n_C106234</td>
        <td>0.06</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>2k ohm</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0402FR-072KL_C60488.html?s_z=n_C60488</td>
        <td>0.06</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>1M ohm</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-RC0402FR-071ML_C138033.html</td>
        <td>0.07</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>470k</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-AC0402JR-07470KL_C227380.html</td>
        <td>0.05</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Resistor/Resettable Fuse</td>
        <td>1A</td>
        <td>https://lcsc.com/product-detail/Resettable-Fuses_JDTfuse-ASMD0805-100_C135331.html?s_z=n_%2509%25206V%25201A%2520100A%25201.95A%25200805%2520Resettable%2520Fuses%2520ROHS</td>
        <td>0.44</td>
        <td>10</td>
        <td>Charging LiPo</td>
    </tr>
    <tr>
        <td>Resistor</td>
        <td>147k</td>
        <td>https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_YAGEO-AC0402FR-07147KL_C226785.html</td>
        <td>0.11</td>
        <td>100</td>
        <td>Resistor</td>
    </tr>
    <tr>
        <td>Switch</td>
        <td>SPST Tactile Switch</td>
        <td>https://lcsc.com/product-detail/Tactile-Switches_USAKRO-UK-B0249-SP25Y_C493280.html</td>
        <td>0.85</td>
        <td>5</td>
        <td>User button</td>
    </tr>
    <tr>
        <td>Switch</td>
        <td>Slide Switch</td>
        <td>https://lcsc.com/product-detail/Slide-Switches_Korean-Hroparts-Elec-K3-1270L-F1_C145858.html?s_z=n_C145858</td>
        <td>0.72</td>
        <td>5</td>
        <td>Power on/off</td>
    </tr>
    <tr>
        <td>LiPo battery</td>
        <td>500mAh, 3.7V</td>
        <td>https://robu.in/product/500mah-pcm-protected-micro-li-po-battery-2/</td>
        <td>6</td>
        <td>2</td>
        <td>For power</td>
    </tr>
    <tr>
        <td>Optical Clear Glue</td>
        <td>LOCA</td>
        <td>https://www.aliexpress.com/item/2255800983414695.html?spm=a2g0o.cart.0.0.346938dabCE0Hi&amp;mp=1&amp;pdp_npi=5%40dis%21USD%21USD%208.86%21USD%208.86%21%21USD%208.86%21%21%21%402101c80217498686257907146e4775%2110000015016065790%21ct%21US%212680287963%21%211%210&amp;_gl=1*mod294*_gcl_aw*R0NMLjE3NDkwODQ1MzguQ2p3S0NBanczZl9CQmhBUEVpd0FhQTNLNUM0SENPdklDSDhYTkZoaGZOOU1fTHVsX1VhVEhQRWtIbXNTWE1wWWE5cmJjR3RUQjYwa0dSb0N0YUVRQXZEX0J3RQ..*_gcl_dc*R0NMLjE3NDkwODQ1MzguQ2p3S0NBanczZl9CQmhBUEVpd0FhQTNLNUM0SENPdklDSDhYTkZoaGZOOU1fTHVsX1VhVEhQRWtIbXNTWE1wWWE5cmJjR3RUQjYwa0dSb0N0YUVRQXZEX0J3RQ..*_gcl_au*MTk0NDQ1MTk2My4xNzQ0MzUwNDU3*_ga*MjgwMjg2NzcwLjE3NDk4NDY2MDg.*_ga_VED1YSGNC7*czE3NDk4NjQxMTEkbzQkZzEkdDE3NDk4Njg2MjYkajMkbDAkaDA.</td>
        <td>9</td>
        <td>1</td>
        <td>For optics arrangement</td>
    </tr>
    <tr>
        <td>Beam Splitter Cube</td>
        <td>10x10x10mm (including shipping) </td>
        <td>https://www.getuscart.com/beam-splitter-cube-optical-glass-dichroic-prism-ratio-5050-spectrome-sicence-3</td>
        <td></td>
        <td>22</td>
        <td>For optics arrangement</td>
    </tr>
    <tr>
        <td>Combiner</td>
        <td>22x20mm(including shipping)</td>
        <td>https://www.aliexpress.us/item/3256807745776887.html?spm=a2g0o.productlist.main.1.1410OiSaOiSa4e&amp;algo_pvid=768d6793-6f7f-49d5-bb5c-2114676308ea&amp;algo_exp_id=768d6793-6f7f-49d5-bb5c-2114676308ea-0&amp;pdp_ext_f=%7B%22order%22%3A%22-1%22%2C%22eval%22%3A%221%22%7D&amp;pdp_npi=4%40dis%21USD%2113.16%2112.50%21%21%2194.46%2189.74%21%402103247017541326536096357ee333%2112000042919022060%21sea%21US%210%21ABX&amp;curPageLogUid=gzjOi8g92PHn&amp;utparam-url=scene%3Asearch%7Cquery_from%3A</td>
        <td>17</td>
        <td>1</td>
        <td>For optics arrangement</td>
    </tr>
    <tr>
        <td>Capacitor</td>
        <td>1uF</td>
        <td>https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL05A105KP5NNNC_C14445.html?s_z=n_C14445</td>
        <td>0.17</td>
        <td>100</td>
        <td>Capacitor</td>
    </tr>
    <tr>
        <td>Capacitor</td>
        <td>100nF</td>
        <td>https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_FH-0402B104K160NT_C41851.html?s_z=n_C41851</td>
        <td>0.1</td>
        <td>100</td>
        <td>Capacitor</td>
    </tr>
    <tr>
        <td>Capacitor</td>
        <td>200pF</td>
        <td>https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_YAGEO-CC0402KRX7R9BB201_C277481.html</td>
        <td>0.12</td>
        <td>100</td>
        <td>Capacitor</td>
    </tr>
    <tr>
        <td>Capacitor</td>
        <td>10uF</td>
        <td>https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Samsung-Electro-Mechanics-CL05A106MQ5NUNC_C15525.html?s_z=n_C15525</td>
        <td>0.06</td>
        <td>10</td>
        <td>Capacitor</td>
    </tr>
    <tr>
        <td>Capacitor</td>
        <td>22uF</td>
        <td>https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_Murata-Electronics-GRM155R60J226ME11D_C415703.html</td>
        <td>0.73</td>
        <td>20</td>
        <td>Capacitor</td>
    </tr>
    <tr>
        <td>LED</td>
        <td>Red</td>
        <td>https://lcsc.com/product-detail/LED-Indication-Discrete_EVERLIGHT-16-213SURC-S530-A3-TR8_C136765.html?s_z=n_red%2520led%25200402</td>
        <td>0.31</td>
        <td>10</td>
        <td>For charging indication</td>
    </tr>
    <tr>
        <td>Inductor</td>
        <td>1.5uH</td>
        <td>https://lcsc.com/product-detail/power-inductors_prod-tech-pspmaa0402-1r5m-anp_C436514.html</td>
        <td>0.74</td>
        <td>5</td>
        <td>Inductor</td>
    </tr>
    <tr>
        <td>PCB</td>
        <td>PCBA</td>
        <td>JLC Estimate (26$ pcb + 16$ shipping, may be more as I havent completed the process)</td>
        <td>40</td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td>LiPo battery voltage meter</td>
        <td>QP38</td>
        <td>https://www.amazon.in/Robodo-QP38-Battery-Voltage-Display/dp/B073Q2ZFKF/ref=sr_1_5?dib=eyJ2IjoiMSJ9.h7pNd3b94wMLvu7R9kZE2eSJ32hl1lhnJQFlfLN4Gd24xE82YwzUwkh3EBS-Zxmqhcc0an2tpR5LRth_B-KnNtE7pN8W4rJ_TZe33bOvyPOtQjmV_vAnpvKywwoU83I3_Bc8Cko2RWheYirfow74KHyUnrcHWWN3DNDxkwo70TQ92bP6v6UaLfMuhW-eBRelz3vvOtdu5FCXq483-jLx-jFEvNaK3QgiHRXgbmL0ei_d_NMcqqMmNXpsakkOPs9weZzdt04Jq2dVCNuaqMc5vZBn6DVezrGdwmTXT11ZPMo.22KFM2wXUmmHYRZHEpZpVcRkNnztCnI54vMCHYcmwyU&dib_tag=se&keywords=lipo+battery+voltage+meter&qid=1754327846&sr=8-5</td>
        <td>2.68</td>
        <td>1</td>
        <td>for testing lipo voltage</td>
    </tr>
    <tr>
        <td>LiPo battery charger</td>
        <td>Type C</td>
        <td>https://www.amazon.in/Converter-Overcharge-Over-Current-Protection-Module/dp/B0DNCRTZXD</td>
        <td>1.6</td>
        <td>1</td>
        <td>for charging lipo</td>
    </tr>
    <tr>
        <td>1.5m Cable</td>
        <td>USB C to Micro HDMI</td>
        <td>https://www.flipkart.com/microware-hdmi-cable-1-5-m-usb-3-1-type-c/p/itm928cffbd6b34a?pid=ACCF8DCB4FU6Z7SN&amp;lid=LSTACCF8DCB4FU6Z7SNBEGLNV&amp;marketplace=FLIPKART&amp;cmpid=content_data-cable_8965229628_gmc&amp;gPromoCode=Freedom_Sale_2025_All</td>
        <td>9</td>
        <td>1</td>
        <td>For display to work, without this display wont work</td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td>JUST TO BE ON THE SAFER SIDE, ADDING 20$ for pcba unexpected costs</td>
        <td>20</td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
        <td></td>
    </tr>
    <tr>
        <td></td>
        <td></td>
        <td>Total Cost</td>
        <td>295.94</td>
        <td></td>
        <td></td>
    </tr>
</table>
