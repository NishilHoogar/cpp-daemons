// to combine both archery and maze
#include<simplecpp>
#include<stdlib.h>
#include<iostream>
#include<Windows.h>
#include<ctime>

// declaration of all functions
void result();
void result2();
void result3();
void maze();    // maze func
int HTP1();      // instructions
int HTP2();
void load1();    // load screen
void load2();
int start_screen();     // start screen
int scorecard();    // scorecard
int menu();     // main menu
int archery();  // archery func

static int score=0;
static int flag[10]={0,0,0,0,0,0,0,0,0,0};

void load1()
{
    const float aFx=650,aFy=450, textW= 1300,textH= 450;
    int i=1;
    Rectangle R(aFx,aFy,1300,900);
    R.setColor(COLOR(1,0,0));
    R.setFill(COLOR(1,0,0));
    Rectangle R0(aFx,aFy,textW,textH);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t(650,450,"PREPARING MAZE....PLEASE WAIT");
    Rectangle R1(aFx,600,500,50);
    Rectangle R2(aFx,600,500,50);
    R2.setColor(COLOR(255,255,255));
    R2.setFill(COLOR(255,255,255));
    R1.setColor(COLOR(39,165,255));
    R1.setFill(COLOR(39,165,255));
    do
    {
        R2.move(20,0);
        wait(0.1);
        i=i+1;
    }while(i<25);
    wait(2);
}

void load2()
{
    const float aFx=650,aFy=450, textW= 1300,textH= 450;
    int i=1;
    Rectangle R(aFx,aFy,1300,900);
    R.setColor(COLOR(1,0,0));
    R.setFill(COLOR(1,0,0));
    Rectangle R0(aFx,aFy,textW,textH);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t(650,450,"PREPARING ENVIRONMENT....PLEASE WAIT");
    Rectangle R1(aFx,600,500,50);
    Rectangle R2(aFx,600,500,50);
    R2.setColor(COLOR(255,255,255));
    R2.setFill(COLOR(255,255,255));
    R1.setColor(COLOR(39,165,255));
    R1.setFill(COLOR(39,165,255));
    do
    {
        R2.move(20,0);
        wait(0.1);
        i=i+1;
    }while(i<25);
    wait(2);
    menu();
}

int start_screen()
{
    int i=1;
    const int ax=800,ay=450;
    const float aFx=650,aFy=450, textW= 1300,textH= 900, bFx=150,bFy=400, bLx=150,bLy=500, bEx=150,bEy=600, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(0,0,60));
    R.setFill(COLOR(0,0,60));
    Rectangle R5(bFx,bFy,100,50);
    R5.setColor(COLOR(255,255,255));
    R5.setFill(COLOR(255,255,255));
    Text t1(bFx,bFy,"Start Game");
    Rectangle R1(bFx,bFy,textWidth(" Start Game "),textHeight());
    wait(0.5);
    Rectangle R6(bLx,bLy,100,50);
    R6.setColor(COLOR(255,255,255));
    R6.setFill(COLOR(255,255,255));
    Text t2(bLx,bLy,"How to Play");
    Rectangle R2(bLx,bLy,textWidth(" How to Play "),textHeight());
    wait(0.5);
    Rectangle R0(bEx,bEy,100,50);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t3(bEx,bEy,"Exit Game");
    Rectangle R3(bEx,bEy,textWidth(" Exit Game "),textHeight());

    Rectangle r(ax,ay,600,700);
    r.scale(1.25);
    r.setColor(COLOR(255,255,255));
    r.setFill(COLOR(255,255,255));
    Text x1(ax,250,"GAME SCENARIO");
    Text x2(ax,300,"You find yourself in the midst of a zombie outbreak!");
    Text x3(ax,330,"Finding no way to protect yourself,");
    Text x4(ax,360,"you come across a maze with a bow and quiver of arrows at the exit");
    Text x5(ax,390,"however there's hoards of zombies at the dead ends.");
    Text x6(ax,420,"make your way through the maze in time without running into any zombies to pass thorugh!");


    //wait(10);
    while(i==1)
    {
        int clickPos = getClick();
        int cx = clickPos/65536;
        int cy = clickPos % 65536;
        if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 && bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2)//TO SELECT HOW TO PLAY
        {
            HTP2();
        }
        if(bFx-bWidth/2<= cx && cx<= bFx+bWidth/2 && bFy-bHeight/2 <= cy && cy <= bFy+bHeight/2)//TO START GAME
        {

            maze();
            return 0;
        }
        if(bEx-bWidth/2<= cx && cx<= bEx+bWidth/2 && bEy-bHeight/2 <= cy && cy <= bEy+bHeight/2)//TO EXIT FROM THE GAME
        {
            exit(0);
        }
        else
        {continue;}
    }
    return(0);
}

int HTP1()
{
    Rectangle r110(0,0,1300,900);
    r110.setColor(COLOR(0,0,60));
    r110.setFill(COLOR(255,255,255));
    r110.scale(10);

    int i=1;
    const float aFx=650,aFy=100, textW= 650,textH= 2000, bLx= 650,bLy= 60, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(255,255,255));
    R.setFill(COLOR(255,255,255));
    Text t3(aFx,aFy,"Kill all zombies to win!");
    Text t4(aFx,200,"Use 'w' to move UP");
    Text t5(aFx,250,"Use 's' to move DOWN");
    Text t51(aFx,300,"Use 'a' to move LEFT");
    Text t52(aFx,350,"Use 'd' to move RIGHT");
    Text t6(aFx,400,"Use 'x' to SHOOT");
    Text t7(aFx,450,"Shoot the zombies and avoid killing the escaping humans");
    Text t8(aFx,500,"Every zombie shot dead earns you 20 points");
    Text t9(aFx,600,"Killing innocent bystanders results in decrement of 10 points");
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

int HTP2()
{
    Rectangle r110(0,0,1300,900);
    r110.setColor(COLOR(0,0,60));
    r110.setFill(COLOR(255,255,255));
    r110.scale(10);

    int i=1;
    const float aFx=650,aFy=100, textW= 650,textH= 2000, bLx= 650,bLy= 60, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(255,255,255));
    R.setFill(COLOR(255,255,255));
    Text t3(aFx,aFy,"Find your way out of maze without getting eaten by zombies!");
    Text t4(aFx,200,"Use 'w' to move UP");
    Text t5(aFx,250,"Use 's' to move DOWN");
    Text t51(aFx,300,"Use 'a' to move LEFT");
    Text t52(aFx,350,"Use 'd' to move RIGHT");
    Text t6(aFx,400,"Avoid running into zombies at dead ends");
    Text t7(aFx,450,"Make it through the maze in one minute");
    Text t8(aFx,500,"Press p to go to main menu");
    Text t9(aFx,600,"");
    Text t10(aFx,700,"");
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
    Rectangle rect(650,400,450,200);
    rect.setColor(COLOR(150,20,20));
    rect.setFill(COLOR(150,20,20));
    Text tea1(650,340,"TOO SLOW");
    Text tea10(650,390,"GAME OVER");
    tea1.scale(5);
    tea10.scale(5);
    wait(3);

}
void result2()
{
    Rectangle rect(650,400,450,200);
    rect.setColor(COLOR(150,20,20));
    rect.setFill(COLOR(150,20,20));
    Text tea11(650,340,"THE ZOMBIES ATE YOUR BRAINS");
    Text tea12(650,390,"GAME OVER");
    tea11.scale(5);
    tea12.scale(5);
    wait(3);
}
void result3()
{
    Rectangle rect(650,400,450,200);
    rect.setColor(COLOR(150,20,20));
    rect.setFill(COLOR(150,20,20));
    Text tea13(650,350,"WINNER");
    Text tea14(650,390,"GAME OVER");
    tea13.scale(5);
    wait(3);
}

int menu()//AN IN GAME MENU FUNCTION TO ALLOW THE PLAYER TO END THE GAME OR VIEW THE HOW TO PLAY INSTRUCTIONS
{
    int i=1;
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(255,99,71));
    r.setFill(COLOR(255,99,71));
    r.scale(10);
    Text t1(650,380,"Press 1 to end the game");
    Text t2(650,410,"Press 2 to go to How to Play menu");
    Text t3(650,440,"Press p to close menu");
    wait(30);
    /*while(i==1)
    {
        XEvent e;//EVENT HANDLING TO TAKE USER INPUT TO FOLLOW CERTAIN INSTRUCTIONS
        nextEvent(e);
        char ev;
        if(keyPressEvent(e))
        {
            ev=charFromEvent(e);
        }
        else if (mouseButtonPressEvent)
        {
            continue;
        }
        switch(ev)
        {
            case '1':scorecard();
            return(0);
            break;
            case '2': HTP1();
            break;
            case 'p':case'P':
            i=0;
            break;

        }
    }*/
    return(0);
}

void maze()
{
Rectangle r110(0,0,1300,900);
r110.setColor(COLOR(0,0,60));
r110.setFill(COLOR(255,255,255));
r110.scale(10);

Line ln(100,100,700,100);
Line ln1(700,100,700,550);
Line ln2(700,600,700,700);
Line ln3(700,700,100,700);
Line ln4(100,100,100,700);

Line br(200,200,200,400);
Line br1(300,200,300,400);
Line br2(150,500,150,650);
Line br3(350,100,350,500);
Line br4(400,200,400,600);
Line br5(500,100,500,650);
Line br27(600,200,600,550);
Line br28(600,600,600,650);
Line br6(650,600,650,700);
Line br7(100,150,250,150);
Line br8(150,300,200,300);
Line br9(100,450,150,450);
Line br10(250,500,350,500);
Line br11(150,600,400,600);
Line br12(250,650,500,650);
Line br13(400,250,450,250);
Line br14(450,450,500,450);
Line br15(500,150,550,150);
Line br16(550,300,600,300);
Line br17(550,550,600,550);
Line br18(550,650,600,650);
Line br19(650,350,700,350);
Line br21(600,600,650,600);
Line br22(200,200,300,200);
Line br23(550,550,550,600);
Line br24(650,400,650,650);
Line br25(600,400,650,400);
Line br26(100,500,150,500);
ln.setColor(GREEN);
ln1.setColor(GREEN);
ln2.setColor(GREEN);
ln3.setColor(GREEN);
ln4.setColor(GREEN);
br.setColor(GREEN);
br1.setColor(GREEN);
br2.setColor(GREEN);
br3.setColor(GREEN);
br4.setColor(GREEN);
br5.setColor(GREEN);
br6.setColor(GREEN);
br7.setColor(GREEN);
br8.setColor(GREEN);
br9.setColor(GREEN);
br10.setColor(GREEN);
br11.setColor(GREEN);
br12.setColor(GREEN);
br13.setColor(GREEN);
br14.setColor(GREEN);
br15.setColor(GREEN);
br16.setColor(GREEN);
br17.setColor(GREEN);
br18.setColor(GREEN);
br19.setColor(GREEN);
//b20.setColor(GREEN);
br21.setColor(GREEN);
br22.setColor(GREEN);
br23.setColor(GREEN);
br24.setColor(GREEN);
br25.setColor(GREEN);
br26.setColor(GREEN);
br27.setColor(GREEN);
br28.setColor(GREEN);

Circle cle1(300,425,20),cle2(225,425,20),cle3(125,525,20),cle4(325,125,20),cle5(525,175,20),cle6(525,425,20),cle7(625,525,20),cle8(625,225,20),cle9(375,125,20),cle10(475,175,20),cle11(325,525,20),cle12(425,575,20);
cle1.setColor(GREEN);
cle1.setFill(GREEN);
cle2.setColor(GREEN);
cle2.setFill(GREEN);
cle3.setColor(GREEN);
cle3.setFill(GREEN);
cle4.setColor(GREEN);
cle4.setFill(GREEN);
cle5.setColor(GREEN);
cle5.setFill(GREEN);
cle6.setColor(GREEN);
cle6.setFill(GREEN);
cle7.setColor(GREEN);
cle7.setFill(GREEN);
cle8.setColor(GREEN);
cle8.setFill(GREEN);
cle9.setColor(GREEN);
cle9.setFill(GREEN);
cle10.setColor(GREEN);
cle10.setFill(GREEN);
cle11.setColor(GREEN);
cle11.setFill(GREEN);
cle12.setColor(GREEN);
cle12.setFill(GREEN);
Circle cle(125,125,20);
cle.setColor(YELLOW);
cle.setFill(YELLOW);

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
XEvent eve;
while(1)
{

    nextEvent(eve);
    x=charFromEvent(eve);
    if(x=='p')
    {
        start_screen();
        break;
    }
    if(x=='w')
    {
    p=a[i][j];
    i--;
    n=a[i][j];
    time2=time(NULL);
    if(time2-time1>=60)
    { result(); break; }
    else if(n==0||p==13&&n==1||p==14&&n==2||p==15&&n==3||p==27&&n==15||p==28&&n==16||p==100&&n==88||p==101&&n==89||p==97&&n==85||p==122&&n==110||
    p==21&&n==9||p==58&&n==46||p==50&&n==38||p==85&&n==73||p==123&&n==111||p==124&&n==112||p==125&&n==113||p==126&&n==114||p==136&&n==124||p==137&&n==125||p==138&&n==126||p==139&&n==127||p==140&&n==128
    ||p==43&&n==31||p==92&&n==80||p==72&&n==60||p==83&&n==71||p==118&&n==106||p==142&&n==130||p==131&&n==119)
    i++;
    else if(n==5|n==6|n==20|n==21|n==35|n==75|n==76|n==77|n==81|n==97|n==101|n==107|n==115)
    {
        cle.setColor(RED);
        cle.setFill(RED);
        result2();
        break;
    }
    else
    cle.move(0,-50);
    }
    else if(x=='s')
    {
    p=a[i][j];
    i++;
    n=a[i][j];
    time2=time(NULL);
    if(time2-time1>=60)
    { result(); break; }

    else if(n==0||n==13&&p==1||n==14&&p==2||n==15&&p==3||n==27&&p==15||n==28&&p==16||n==100&&p==88||n==101&&p==89||n==97&&p==85||n==122&&p==110||
    n==21&&p==9||n==58&&p==46||n==50&&p==38||n==85&&p==73||n==123&&p==111||n==124&&p==112||n==125&&p==113||n==126&&p==114||n==136&&p==124||n==137&&p==125||n==138&&p==126||n==139&&p==127||n==140&&p==128
    ||n==43&&p==31||n==92&&p==80||n==72&&p==60||n==83&&p==71||n==118&&p==106||n==142&&p==130||n==131&&p==119)
    i--;
    else if(n==5|n==6|n==20|n==21|n==35|n==75|n==76|n==77|n==81|n==97|n==101|n==107|n==115)
    {
        cle.setColor(RED);
        cle.setFill(RED);
        result2();
        break;
    }
    else
    cle.move(0,50);
    }
    else if(x=='a')
    {
        p=a[i][j];
        j--;
        n=a[i][j];
        time2=time(NULL);
        if(time2-time1>=60)
        { result(); break; }

        else if(n==0||n==26&&p==27||n==38&&p==39||n==50&&p==51||n==62&&p==63||n==28&&p==29||n==40&&p==10||n==52&&p==53||n==64&&p==65||n==5&&p==6||
        n==40&&p==41||n==17&&p==18||n==29&&p==30||n==41&&p==42||n==53&&p==54||n==65&&p==66||n==77&&p==78||n==89&&p==90||n==97&&p==98||n==109&&p==110||n==121&&p==122||n==8&&p==9||n==20&&p==21||
        n==32&&p==33||n==44&&p==45||n==56&&p==57||n==68&&p==69||n==80&&p==81||n==92&&p==93||n==104&&p==105||n==116&&p==117||n==128&&p==129||n==30&&p==31||n==42&&p==43||n==54&&p==55||
        n==66&&p==67||n==78&&p==79||n==90&&p==91||n==102&&p==103||n==114&&p==115||n==34&&p==35||n==46&&p==47||n==58&&p==59||n==70&&p==71||n==82&&p==83||n==94&&p==95||n==106&&p==107||
        n==130&&p==131||n==117&&p==118||n==83&&p==84||n==95&&p==96||n==107&&p==108||n==119&&p==120||n==131&&p==132||n==143&&p==144)
        j++;
        else if(n==5|n==6|n==20|n==21|n==35|n==75|n==76|n==77|n==81|n==97|n==101|n==107|n==115)
    {
        cle.setColor(RED);
        cle.setFill(RED);
        result2();
        break;
    }
        else
        cle.move(-50,0);
    }
    else if(x=='d')
    {
        p=a[i][j];
        j++;
        n=a[i][j];
        time2=time(NULL);
        if(time2-time1>=60)
        { result(); break; }
        else if(n==1230)
        {
            /*Rectangle rect(400,400,200,200);
            rect.setColor(GREEN);
            rect.setFill(GREEN);
            Text tst(400,400,"::WINNER::");
            tst.scale(10);
            tst.setColor(BLACK);*/
            wait(1);
            { result3();
              load2();
             }
        }
        else if(n==0||p==26&&n==27||p==38&&n==39||p==50&&n==51||p==62&&n==63||p==28&&n==29||p==40&&n==10||p==52&&n==53||p==64&&n==65||p==5&&n==6||
        p==40&&n==41||p==17&&n==18||p==29&&n==30||p==41&&n==42||p==53&&n==54||p==65&&n==66||p==77&&n==78||p==89&&n==90||p==97&&n==98||p==109&&n==110||p==121&&n==122||p==8&&n==9||p==20&&n==21||
        p==32&&n==33||p==44&&n==45||p==56&&n==57||p==68&&n==69||p==80&&n==81||p==92&&n==93||p==104&&n==105||p==116&&117||p==128&&n==129||p==30&&n==31||p==42&&n==43||p==54&&n==55||
        p==66&&n==67||p==78&&n==79||p==90&&n==91||p==102&&n==103||p==114&&n==115||p==34&&n==35||p==46&&n==47||p==58&&n==59||p==70&&n==71||p==82&&n==83||p==94&&n==95||p==106&&n==107||
        p==130&&n==131||p==117&&n==118||p==83&&n==84||p==95&&n==96||p==107&&n==108||p==119&&n==120||p==131&&n==132||p==143&&n==144)
        j--;
        else if(n==5|n==6|n==20|n==21|n==35|n==75|n==76|n==77|n==81|n==97|n==101|n==107|n==115)
    {
        cle.setColor(RED);
        cle.setFill(RED);
        result2();
        break;
    }
        else
        cle.move(50,0);
    }
    else if(x=='v')
    {break;}


}
if(x=='v')
{
repeat(3)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(1)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(3)
{
    wait(0.5);
    cle.move(-50,0);
}
repeat(5)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(3)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(4)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(8)
{
    wait(0.5);
    cle.move(0,-50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);

}
repeat(1)
{
    wait(0.5);
    cle.move(0,50);

}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);

}

repeat(4)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(1)
{
    wait(0.5);
    cle.move(-50,0);
}
repeat(2)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(2)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(5)
{
    wait(0.5);
    cle.move(-50,0);
}
repeat(1)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(6)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(4)
{
    wait(0.5);
    cle.move(0,-50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(3)
{
    wait(0.5);
    cle.move(0,-50);
}
repeat(1)
{
    wait(0.5);
    cle.move(-50,0);
}
repeat(2)
{
    wait(0.5);
    cle.move(0,-50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(1)
{
    wait(0.5);
    cle.move(0,-50);
}
repeat(2)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(3)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(1)
{
    wait(0.5);
    cle.move(-50,0);
}
repeat(1)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(1)
{
    wait(0.5);
    cle.move(50,0);
}
repeat(4)
{
    wait(0.5);
    cle.move(0,50);
}
repeat(3)
{
    wait(0.5);
    cle.move(50,0);
}
    result3();
}

wait(2);
}

// Main Function
main_program
{
    initCanvas("Maze by CPP_Deamons",1300,900);
    Rectangle Rt(650,450,1300,900);
    Rt.setColor(COLOR(1,0,0));
    Rt.setFill(COLOR(1,0,0));
    //load1();
    start_screen();

}
