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

At first we open up curly brackets to start a new block of information.
Then we specify a class by first saying its compiled name the name we would like to use in our programm and where we can find an instance to the class.
We di this by opening up angled brackets and first saying the compiled name then the signature then where you we can find the instance in if its the same as the class signature we will look inside the class if its diffrent we look for it using the map which contains already loaded classes. At last we specify if the instance is static. The way we do it for fields/methods is similar (note arrays are fields!).

Latest LDRF:

{

  class: "ave" -> "Minecraft" <"S",Lave;,Lave;,true> {
    fields: [<true,"S","instance",Lave;>, <false,"ap","right_click_delay_timer",I>, <false,"Y","timer",Lavl;>]
    methods: [<false,"aw","click_mouse",()V>, <false,"ax","right_click_mouse",()V>]
  };
  
  class: "avl" -> "Timer" <"Y",Lavl;,Minecraft,false> {
    fields: [<false,"d","timer_speed",F>]
    methods: []
  };

  class: "org/lwjgl/opengl/Display" -> "Display" <?> {
    fields: []
    methods: [<true,"isActive","is_active",()Z>]
  }

  class: "bew" -> "EntityPlayerSp" <"h",Lbew;,Minecraft,false> {
    fields: [<false,"W","ticks_existed",I>]
    methods: []
  };
  
};
