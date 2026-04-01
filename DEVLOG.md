## 2026 - 03 - 21
Began implementing ArrayStack class by completing size, empty 
and push methods. I will fully finish the stack next session.
## 2026 - 03 -23
Finished implementation of ArrayStack class. Will begin main.cpp
adventures next time.
## 2026 - 03 - 27
Oops I haven't done this in a while.. Anyways, today I implemeneted
the tokenzier to convert inputs into token objects instead of Strings.
It seperates integers and operators while ignoring whitespaces.
## 2026 - 03 - 27
Made isValidPostFix using ArrayStack class. Used stack-based appraoch
by pushing values for numbers and popping operators. The push method is
throwing flags so I will have to fix that soon but. We shall see.
## 2026 - 03 - 30
Soo... I lost track of time. and I realize now that this is due in 24 hours
and I definitely don't have 10 commits so... I'm just gonna take that L sadly,
completely my fault. Anyways. I first fixed the errors in isValidPostFix. it was
due to the ArrayStack being string rather than int so it wouldn't take the 1.
Fixed that! Then, I implemented evalPostFix, precendence, and isValidInfix. Normally,
I would've broken up these methods across multiple commits however due to my time
constraint I had to bear down and do a huge chunk. Sorry for failing you Mrs. Manju.
Going to finish up this program entirely tmrw!! Gonna do infixToPostfix and fine tune
everything else.
## 2026 - 03 -31
Okay! I finished the last method, infixToPostfix. This one took some time and some
research because I was really confused. I will admit I did ask ChatGPT for some assistance
regarding how to pass the token object through push_back() - which I discovered using the {}
syntax initializes the argument as a token. I was really stuck on this one so it took me a while.