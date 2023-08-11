# EtherCAT-Mini-DAQ

This project is a multi-channel data aquisistion system running on an EtherCAT network.

The key idea is that with an EasyCAT shield board an arduino may be made into an EtherCAT slave device. Then sensors may be connected to the arduino and all data transmitted over single ethernet cable.
The EtherCAT master device is a NI CompactRIO 9082 which allows data to be logged and visualised in a labVIEW virtual instrument. 

Full instructions and information may be found in the supporting documents attatched:

Document 1 - Overview : An overview of the purpose, design and technical specification of the EtherCAT Mini-DAQ.
Document 2 - How-to-Use : A startup guide for use in default configuration.
Document 3 - Configuration : A guide to re-configuring the Mini-DAQ (for >8 analogue channels or additional digital sensors beyond accelerometer)
