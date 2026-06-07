# Isoceles Barndoor Sky Tracker
## Parts
* See bom.csv for parts list
* 3D printed parts use 20% infill
* Two of the following parts will need to be printed:
  * Part 2
  * Part 3
  * Part 5
  * Part 12

## Build Instructions
### Tools
1. M4x0.7 tap
2. Pliers
3. M2.5 allen key
4. Phillips head screw driver

### Steps
1. Print parts and acquire hardware per bom.csv
2. Clean up 3d printed parts
    1. Ensure gears are free of support material
    2. Ensure Part 6 has all internal support material removed
3. Tap threads into Part 6 and 10

![M4 tap locations](./images/m4_tap_locations.png)

4. Begin assembly of pivot with Part 2 and 3
   1. Bearing is fit between parts per diagram

![Pivot Exploded](./images/pivot_exploded.png)

5. Begin motor assembly with Part 5, 6, 9, 10, 11, 12 and spur center

![](./images/internal_exploded_1.png)
![](./images/internal_exploded_2.png)
![](./images/gear_relations.png)
![M4 washer location](./images/washer_location.png)
![M4 screw locations](./images/m4_screw_locations.png)
![](./images/bottom_assembly.jpg)
![](./images/bottom_assembly_close_up.jpg)

6. Attach 1/4 round cap to 1/4-20 threaded rod
   1. Use thread locker red or an adhesive that works on metal

![](./images/rod_with_nut_capture.jpg)

7. Wooden components
   1. Primary concern with wooden components is that the motor relative to pivot is 29 cm (see math section below)
   2. Dimensions in mm, closest imperial equivalent is good enough (**stock must be 3/4" for pivot**)

![](./images/wood_dimensions.png)

8. Electronics wiring as below
   1. Setup Arduino IDE for Nano board
      1. https://docs.arduino.cc/tutorials/nano/nano-getting-started/
   2. Electrical connections diagram below
   3. Open barn-door-tracker.ino in Arduino IDE and upload to board

![](./images/electronics.jpg)
![Electrical Diagram](./images/circuit_bdst.png)

### Math
To support tracking the stars we need a few constants:

* Sidereal day (https://en.wikipedia.org/wiki/Sidereal_time)
  * 86164.09056 (seconds)
* Law of Cosines (https://en.wikipedia.org/wiki/Law_of_cosines)
```math
c^2 = a^2 + b^2 - 2ab \cos(\Beta)
```
Solved for the third side knowing two sides and an angle
```math
c = \sqrt{a^2 + b^2 - 2ab \cos(\Beta)}
```

* Steps per full rotation in 28BYJ-48 at full stepping mode
  * 2048 (4096 for half stepping mode)
* Rotations per cm of rod extension
  * 7.874
* Length of two sides
  * 29 cm

Now we solve for time over which the instrument is running.  Assumes starting angle is effectively zero (not entirely true, but close enough).

Radians per second $`(R) = 2 * \pi / 86164.09056`$

Radians at Time T $`R(T) = T * ( 2 * \pi / 86164.09056 )`$

Bolt extension (cm/T) $`B(T) = \sqrt{29^2+29^2-2*29*29*\cos(R(T))}`$

Rotations at Time T $`Rot(T) = B(T)/7.874cm`$

Solving for time T our steps per second comes out to ~66.00355.  This means we can drive the motor at 66 steps per second over the duration of the bolt and fine, but also means we need to get the 29cm side length correct!
