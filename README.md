# CWhiteout
Required Libraries:

https://www.sfml-dev.org/index.php

https://www.oracle.com/java/technologies/downloads/#jdk17-windows

#Loaderfile Documentation (LDRF):

Loader files store the information whiteout needs to load java classes, methods and fields into the dll so that we can access them and modify their values.

This is an example:

```ldrf
{

  class: "ave" -> "Minecraft" <"S",Lave;,Lave;,true> {
    fields: [<true,"S","instance",Lave;>, <false,"ap","right_click_delay_timer",I>, <false,"Y","timer",Lavl;>]
    methods: [<false,"aw","click_mouse",()V>, <false,"ax","right_click_mouse",()V>]
  };
  
  class: "avl" -> "Timer" <"Y",Lavl;,Minecraft,false> {
    fields: [<false,"d","timer_speed",F>]
    methods: []
  };

```
