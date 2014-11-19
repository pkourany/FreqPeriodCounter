FreqPeriodCounter
================

Frequency Counter Library
Version 28-5-2013
Copyright (C) 2011  Albert van Dalen http://www.avdweb.nl

Refer to http://www.avdweb.nl/arduino/hardware-interfacing/frequency-period-counter.html for details

``` 
Release Notes
-------------
17-12-2011 timeFunctionPtr to select millis or micros instead of bool variable
17-12-2011 New function ready()
22-04-2012 poll() counts all transients instead of low-high transients
5-5-2013 if(transientCount >= 2) // the first 2 measurements are invalid
28-5-2013 measurements are valid from start, added synchronize() 
18-11-2014 Adapted for Spark Core by Paul Kourany


			<------------- period ------------>
				pulseWidth
				_____________                      ______________                     
			||             ||                  ||              ||  
			||             ||  pulseWidthLow   ||              ||              |
______________||             ||__________________||              ||______________|
		
transientCount 1             2                   1               2               1
transientTime ^              ^                   ^               ^
level                1                 0                  1                0       
debounceTime  <-->           <-->                <-->            <--> 
																<- elapsedTime ->
```