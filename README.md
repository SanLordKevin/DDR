# DDR
SW for DDR

For the RP-eS40-ST
at 10kg we have approx 400 Ohm
at 1200g               2k Ohm
at 400g                5k Ohm
at 800g                3k Ohm 
at 10g                 200k Ohm


In this project we will use a 3k Ohm resistance for the resitance divider,
so at 800g load we will arrive near 512 mV and will use this value for the threshold.
In this condition if the sampled value arrives at 850mV we are close to the 10kg load,
 that is the maximum load for the sensor.
