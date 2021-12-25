#include<simplecpp>
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<ctime>
int HTP()
{
    int i=1;
    const float aFx=650,aFy=100, textW= 650,textH= 2000, bLx= 650,bLy= 60, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(155,55,55));
    R.setFill(COLOR(155,55,55));
    Text t3(aFx,aFy,"There's a zombie attack, find a way to exit the maze to escape from the zombies! ");
    Text t4(aFx,200,"Use 'w' to move UP");
    Text t5(aFx,250,"Use 's' to move DOWN");
    Text t51(aFx,300,"Use 'a' to move LEFT");
    Text t52(aFx,350,"Use 'd' to move RIGHT");
    Text t7(aFx,450,"");
    Text t8(aFx,500,"");
    Text t9(aFx,600,"");
    Text t10(aFx,700,"Hit key p to exit midgame");
    Text tx(bLx,bLy,"BACK");
    Rectangle b(bLx,bLy,textWidth(" BACK "),textHeight());
    while(i==1)
    {
        int clickPos = getClick();
        int cx = clickPos/65536;
        int cy = clickPos % 65536;
        if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 && bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2)
        {
            i=0;
            return(0);
        }
        else
        {
            continue;
        }
    }
    return(0);
}
void result()
{
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(150,20,20));
    r.setFill(COLOR(150,20,20));
    Text t1(650,390,"GAME OVER");
    wait(3);

}
void game()
{
//Write your code here



Line l(100,100,700,100);
Line l1(700,100,700,550);
Line l2(700,600,700,700);
Line l3(700,700,100,700);
Line l4(100,100,100,700);

Line b(200,200,200,400);
Line b1(300,200,300,400);
Line b2(150,500,150,650);
Line b3(350,100,350,500);
Line b4(400,200,400,600);
Line b5(500,100,500,650);
Line b27(600,200,600,550);
Line b28(600,600,600,650);
Line b6(650,600,650,700);
Line b7(100,150,250,150);
Line b8(150,300,200,300);
Line b9(100,450,150,450);
Line b10(250,500,350,500);
Line b11(150,600,400,600);
Line b12(250,650,500,650);
Line b13(400,250,450,250);
Line b14(450,450,500,450);
Line b15(500,150,550,150);
Line b16(550,300,600,300);
Line b17(550,550,600,550);
Line b18(550,650,600,650);
Line b19(650,350,700,350);
Line b21(600,600,650,600);
Line b22(200,200,300,200);
Line b23(550,550,550,600);
Line b24(650,400,650,650);
Line b25(600,400,650,400);
Line b26(100,500,150,500);
l.setColor(GREEN);
l1.setColor(GREEN);
l2.setColor(GREEN);
l3.setColor(GREEN);
l4.setColor(GREEN);
b.setColor(GREEN);
b1.setColor(GREEN);
b2.setColor(GREEN);
b3.setColor(GREEN);
b4.setColor(GREEN);
b5.setColor(GREEN);
b6.setColor(GREEN);
b7.setColor(GREEN);
b8.setColor(GREEN);
b9.setColor(GREEN);
b10.setColor(GREEN);
b11.setColor(GREEN);
b12.setColor(GREEN);
b13.setColor(GREEN);
b14.setColor(GREEN);
b15.setColor(GREEN);
b16.setColor(GREEN);
b17.setColor(GREEN);
b18.setColor(GREEN);
b19.setColor(GREEN);
//b20.setColor(GREEN);
b21.setColor(GREEN);
b22.setColor(GREEN);
b23.setColor(GREEN);
b24.setColor(GREEN);
b25.setColor(GREEN);
b26.setColor(GREEN);
b27.setColor(GREEN);
b28.setColor(GREEN);


Circle c(125,125,20);
c.setColor(YELLOW);
c.setFill(YELLOW);

int time1=time(NULL)+01;
wait(1);
int time2=time(NULL);
int i=1,j=1,p,n, a[14][14]={{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                            {0,1,2,3,4,5,6,7,8,9,10,11,12,0},
                            {0,13,14,15,16,17,18,19,20,21,22,23,24,0},
                            {0,25,26,27,28,29,30,31,32,33,34,35,36,0},
                            {0,37,38,39,40,41,42,43,44,45,46,47,48,0},
                            {0,49,50,51,52,53,54,55,56,57,58,59,60,0},
                            {0,61,62,63,64,65,66,67,68,69,70,71,72,0},
                            {0,73,74,75,76,77,78,79,80,81,82,83,84,0},
                            {0,85,86,87,88,89,90,91,92,93,94,95,96,0},
                            {0,97,98,99,100,101,102,103,104,105,106,107,108,0},
                            {0,109,110,111,112,113,114,115,116,117,118,119,120,1230},
                            {0,121,122,123,124,125,126,127,128,129,130,131,132,0},
                            {0,133,134,135,136,137,138,139,140,141,142,143,144,0},
                            {0,0,0,0,0,0,0,0,0,0,0,0,0,0} };

char x;
XEvent e;
while(1)
{
int here;
here:
    nextEvent(e);
    x=charFromEvent(e);

    if(x=='w')
    {
    p=a[i][j];
    i--;
    n=a[i][j];
    time2=time(NULL);
    if(time2-time1>=40)
    { result(); break; }
    else if(n==0||p==13&&n==1||p==14&&n==2||p==15&&n==3||p==27&&n==15||p==28&&n==16||p==100&&n==88||p==101&&n==89||p==97&&n==85||p==122&&n==110||
    p==21&&n==9||p==58&&n==46||p==50&&n==38||p==85&&n==73||p==123&&n==111||p==124&&n==112||p==125&&n==113||p==126&&n==114||p==136&&n==124||p==137&&n==125||p==138&&n==126||p==139&&n==127||p==140&&n==128
    ||p==43&&n==31||p==92&&n==80||p==72&&n==60||p==83&&n==71||p==118&&n==106||p==142&&n==130||p==131&&n==119)
    i++;
    else
    c.move(0,-50);
    }
    else if(x=='s')
    {
    p=a[i][j];
    i++;
    n=a[i][j];
    time2=time(NULL);
    if(time2-time1>=40)
    { result(); break; }
    else if(n==0||n==13&&p==1||n==14&&p==2||n==15&&p==3||n==27&&p==15||n==28&&p==16||n==100&&p==88||n==101&&p==89||n==97&&p==85||n==122&&p==110||
    n==21&&p==9||n==58&&p==46||n==50&&p==38||n==85&&p==73||n==123&&p==111||n==124&&p==112||n==125&&p==113||n==126&&p==114||n==136&&p==124||n==137&&p==125||n==138&&p==126||n==139&&p==127||n==140&&p==128
    ||n==43&&p==31||n==92&&p==80||n==72&&p==60||n==83&&p==71||n==118&&p==106||n==142&&p==130||n==131&&p==119)
    i--;
    else
    c.move(0,50);
    }
    else if(x=='a')
    {
        p=a[i][j];
        j--;
        n=a[i][j];
        time2=time(NULL);
        if(time2-time1>=40)
        { result(); break; }
        else if(n==0||n==26&&p==27||n==38&&p==39||n==50&&p==51||n==62&&p==63||n==28&&p==29||n==40&&p==10||n==52&&p==53||n==64&&p==65||n==5&&p==6||
        n==40&&p==41||n==17&&p==18||n==29&&p==30||n==41&&p==42||n==53&&p==54||n==65&&p==66||n==77&&p==78||n==89&&p==90||n==97&&p==98||n==109&&p==110||n==121&&p==122||n==8&&p==9||n==20&&p==21||
        n==32&&p==33||n==44&&p==45||n==56&&p==57||n==68&&p==69||n==80&&p==81||n==92&&p==93||n==104&&p==105||n==116&&p==117||n==128&&p==129||n==30&&p==31||n==42&&p==43||n==54&&p==55||
        n==66&&p==67||n==78&&p==79||n==90&&p==91||n==102&&p==103||n==114&&p==115||n==34&&p==35||n==46&&p==47||n==58&&p==59||n==70&&p==71||n==82&&p==83||n==94&&p==95||n==106&&p==107||
        n==130&&p==131||n==117&&p==118||n==83&&p==84||n==95&&p==96||n==107&&p==108||n==119&&p==120||n==131&&p==132||n==143&&p==144)
        j++;
        else
        c.move(-50,0);
    }
    else if(x=='d')
    {
        p=a[i][j];
        j++;
        n=a[i][j];
        time2=time(NULL);
        if(time2-time1>=40)
        { result(); break; }
        else if(n==1230)
        {
            Text t(400,400,"::WINNER::");
            t.scale(10);
            t.setColor(GREEN);
            wait(5);
            { result(); break; }
        }
        else if(n==0||p==26&&n==27||p==38&&n==39||p==50&&n==51||p==62&&n==63||p==28&&n==29||p==40&&n==10||p==52&&n==53||p==64&&n==65||p==5&&n==6||
        p==40&&n==41||p==17&&n==18||p==29&&n==30||p==41&&n==42||p==53&&n==54||p==65&&n==66||p==77&&n==78||p==89&&n==90||p==97&&n==98||p==109&&n==110||p==121&&n==122||p==8&&n==9||p==20&&n==21||
        p==32&&n==33||p==44&&n==45||p==56&&n==57||p==68&&n==69||p==80&&n==81||p==92&&n==93||p==104&&n==105||p==116&&117||p==128&&n==129||p==30&&n==31||p==42&&n==43||p==54&&n==55||
        p==66&&n==67||p==78&&n==79||p==90&&n==91||p==102&&n==103||p==114&&n==115||p==34&&n==35||p==46&&n==47||p==58&&n==59||p==70&&n==71||p==82&&n==83||p==94&&n==95||p==106&&n==107||
        p==130&&n==131||p==117&&n==118||p==83&&n==84||p==95&&n==96||p==107&&n==108||p==119&&n==120||p==131&&n==132||p==143&&n==144)
        j--;
        else
        c.move(50,0);
    }
    else if(x=='v')
    {break;}
}
while(x=='v')
{
repeat(3)
{
    wait(0.5);
    c.move(50,0);
}
repeat(1)
{
    wait(0.5);
    c.move(0,50);
}
repeat(3)
{
    wait(0.5);
    c.move(-50,0);
}
repeat(5)
{
    wait(0.5);
    c.move(0,50);
}
repeat(1)
{
    wait(0.5);
    c.move(50,0);
}
repeat(2)
{
    wait(0.5);
    c.move(0,50);
}
repeat(4)
{
    wait(0.5);
    c.move(50,0);
}
repeat(7)
{
    wait(0.5);
    c.move(0,-50);
}
repeat(2)
{
    wait(0.5);
    c.move(50,0);

}
repeat(5)
{
    wait(0.5);
    c.move(0,50);
}
repeat(1)
{
    wait(0.5);
    c.move(-50,0);
}
repeat(4)
{
    wait(0.5);
    c.move(0,50);
}
repeat(4)
{
    wait(0.5);
    c.move(-50,0);
}
repeat(1)
{
    wait(0.5);
    c.move(0,50);
}
repeat(6)
{
    wait(0.5);
    c.move(50,0);
}
repeat(10)
{
    wait(0.5);
    c.move(0,-50);
}
repeat(2)
{
    wait(0.5);
    c.move(50,0);
}
repeat(4)
{
    wait(0.5);
    c.move(0,50);
}
repeat(1)
{
    wait(0.5);
    c.move(50,0);
}
repeat(4)
{
    wait(0.5);
    c.move(0,50);
}
repeat(3)
{
    wait(0.5);
    c.move(50,0);
}
    result();
    break;
}

wait(5);
// wait(60);
}
main_program
{
    initCanvas("welcome",1300,900);
    Rectangle R(650,450,1300,900);
    R.setColor(COLOR(1,0,0));
    R.setFill(COLOR(1,0,0));
    HTP();
    game();
}
