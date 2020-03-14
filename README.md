<pre>
// ##################################################### ###############################################
// RF3Sens (RoboForum triangulation range sensor)
// http://roboforum.ru/forum107/topic15929.html (official language for this forum - russian)
// MIT License
// 2015-2016
// Dmitry Lilik (aka Dmitry__ @ RoboForum.ru)
// Andrey Pozhogin (aka dccharacter @ RoboForum.ru)
// Sergey Taranenko (aka setar @ RoboForum.ru)
// ##################################################### ###############################################
</pre>

High precision (0.01+ mm) optical barrier to the table surface of 3D printers.
Based on the analysis of the illumination pattern of the CCD matrix (from the mouse) by scattered radiation from a laser source,
according to the principle of a triangle, at predetermined installation angles of the laser and the matrix.
It does not depend on the type of table material (theoretically, the technique is still in development).

The claimed accuracy has already been obtained by practical means on prototypes.
<pre>
vvv ========= 3D printer printing carriage =============== vvv
  - sensor ------- laser - (sensor circuit board)
         \\\\ ||||
            \ | |
             \ | |
              \ | |
               \ | |
                \ | |
                 \ | |
                  \ | |
                   \ | |
                    \ | |
                     \ | |
------ level ------- * --- tripping -------------------
                      | \ |
                      | \
    here the sensor does not see the laser spot and there is no response
^^^ ================ 3D printer table ==================== ^^^
</pre>


* Schemes for connecting different arduin (and other microcontrollers) in the doc folder