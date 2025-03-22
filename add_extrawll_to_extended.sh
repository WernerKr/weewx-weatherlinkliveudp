#!/bin/bash
weectl database add-column co2_Temp --type=REAL -y
weectl database add-column co2_Hum --type=REAL -y
weectl database add-column co2_Batt --type=REAL -y
weectl database add-column THSW --type=REAL -y
weectl database add-column THW --type=REAL -y
weectl database add-column windGustSpeed10 --type=REAL -y
weectl database add-column sunshine_hours --type=REAL -y
weectl database add-column sunshine_time --type=REAL -y
weectl database add-column sunshineDur --type=REAL -y
weectl database add-column rainDur --type=REAL -y
weectl database add-column hailDur --type=REAL -y
