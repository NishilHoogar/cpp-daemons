#include<simplecpp>
#include<stdlib.h>

/*Project Name: Archery */
static int score=0;//Used for saving score of player throughout program
static int flag[10]={0,0,0,0,0,0,0,0,0,0};
int game();
int HTP();
void load()//FUNCTION FOR THE LOADING SCREEN
{
    const float aFx=650,aFy=450, textW= 1300,textH= 450;
    int i=1;
    Rectangle R(aFx,aFy,1300,900);
    R.setColor(COLOR(1,0,0));
    R.setFill(COLOR(1,0,0));
    Rectangle R0(aFx,aFy,textW,textH);
    R0.setColor(COLOR(255,255,255));
    R0.setFill(COLOR(255,255,255));
    Text t(650,450,"LOADING SHOOTING RANGE....PLEASE WAIT");
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

int start_screen()//FUNCTION FOR THE START SCREEN OF THE GAME
{
    int i=1;
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
    while(i==1)
    {
        int clickPos = getClick();
        int cx = clickPos/65536;
        int cy = clickPos % 65536;
        if(bLx-bWidth/2<= cx && cx<= bLx+bWidth/2 && bLy-bHeight/2 <= cy && cy <= bLy+bHeight/2)//TO SELECT HOW TO PLAY
        {
            HTP();
        }
        if(bFx-bWidth/2<= cx && cx<= bFx+bWidth/2 && bFy-bHeight/2 <= cy && cy <= bFy+bHeight/2)//TO START GAME
        {
            game();
            return(0);
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

int HTP()//FUNCTION FOR THE HOW TO PLAY INSTRUCTIONS
{
    int i=1;
    const float aFx=650,aFy=100, textW= 650,textH= 2000, bLx= 650,bLy= 60, bWidth=150,bHeight=50;
    Rectangle R(aFx,aFy,textW,textH);
    R.setColor(COLOR(255,255,255));
    R.setFill(COLOR(255,255,255));
    Text t3(aFx,aFy,"There's a zombie infection spreading, shoot all infected zombies in the brain to kill them.Save your friends before they get infected !");
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

int scorecard()//FUNTION TO DISPLAY THE FINAL SCORE OF THE PLAYER
 {
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(255,99,71));
    r.setFill(COLOR(255,99,71));
    Text t1(650,390,"GAME OVER");
    Text t2(620,450,"SCORE=");
    Text t3(670,450,(char)score);
    wait(3);
    score=0;
    for(int i=0;i<10;i++)
        { flag[i]=0;}
    start_screen();//AFTER VIEWING SCORECARD WE RETURN TO THE START SCREEN AGAIN
    return(0);
 }

int menu()//AN IN GAME MENU FUNCTION TO ALLOW THE PLAYER TO END THE GAME OR VIEW THE HOW TO PLAY INSTRUCTIONS
{
    int i=1;
    Rectangle r(650,400,450,200);
    r.setColor(COLOR(255,99,71));
    r.setFill(COLOR(255,99,71));
    Text t1(650,380,"Press 1 to end the game");
    Text t2(650,410,"Press 2 to go to How to Play menu");
    Text t3(650,440,"Press p to close menu");
    while(i==1)
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
            case '2': HTP();
            break;
            case 'p':case'P':
            i=0;
            break;

        }
    }
    return(0);
}

class Body:public Composite //Creating body and feet of the man,class Body is a child class of Composite class
{
    Line *bd[7];
    //Circle *cir[2];
public:
    Body(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        bd[0]=new Line (58,82,58,150,this); //body
        bd[1]=new Line (58,150,38,142,this);//leg
        bd[2]=new Line (58,125,82,125,this);//
        bd[3]=new Line (58,99,35,105,this);//arm1 part2
        bd[4]=new Line (35,105,58,85,this);//arm1 part1
        bd[5]=new Line (58,85,102,99,this);//hand nearest to arrow
        bd[6]=new Line (82,125,82,150,this);
        //cir[0]= new Circle(40,144,5,this);
        //cir[1]= new Circle(84,144,5,this);
        //cir[0]->setColor(c);
        //cir[0]->setFill(c);
        //cir[1]->setColor(c);
       // cir[1]->setFill(c);
        bd[0]->setColor(COLOR(144,238,144));
        bd[0]->setFill(c);
        bd[1]->setColor(COLOR(210,105,30));
        bd[1]->setFill(c);
        bd[2]->setColor(COLOR(144,238,144));
        bd[2]->setFill(c);
        bd[3]->setColor(COLOR(0,100,0));
        bd[3]->setFill(c);
        bd[4]->setColor(COLOR(144,238,144));
        bd[4]->setFill(c);
        bd[5]->setColor(COLOR(144,238,144));
        bd[5]->setFill(c);
        bd[6]->setColor(COLOR(210,105,30));
        bd[6]->setFill(c);
    }
};

class Bow:public Composite //Creating bow held by the man,class Bow is a child class of Composite
{
    Line *bw[4];
    public:
    Bow(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        bw[0]=new Line (60,97,89,77,this);
        bw[1]=new Line (89,77,102,99,this);//upper-front part of arrow.
        bw[2]=new Line (102,99,89,119,this);
        bw[3]=new Line (89,117,60,97,this);//back-lower part of arrow.
        bw[0]->setColor(COLOR(255,255,255));
        bw[1]->setColor(COLOR(193, 154, 107));
        bw[2]->setColor(COLOR(193, 154, 107));
        bw[3]->setColor(COLOR(255,255,255));
    }
};
/*Creating the arrow held by the man;class Arrow is the child of class Composite
 This arrow shoots through the balloons in the game*/
class Arrow:public Composite
{
    Line *ar[3];
    public:
    Arrow(double x,double y,Composite* owner=NULL):Composite(x,y,owner)
    {
        ar[0]= new Line (104,75,164,75,this);
        ar[1]= new Line (154,65,164,75,this);
        ar[2]= new Line (154,85,164,75,this);
        ar[0]->setColor(COLOR(192,192,192));
        ar[0]->setFill(COLOR(192,192,192));
        ar[1]->setColor(COLOR(192,192,192));
        ar[1]->setFill(COLOR(192,192,192));
        ar[2]->setColor(COLOR(192,192,192));
        ar[2]->setFill(COLOR(192,192,192));
    }
 /*
	   movement()---->used to release arrow upon click
	   determines the arrow release position based on y co-ordinate of static arrow y coordinate.
 */
    void movement(double x,double y)
    {
        Arrow a2(x,y);
        repeat(30)
        {
            a2.move(50,0);
            wait(0.01);
        }
    }
};

/* Creating a class man which is a child class of class Composite.
   Integrating the head, body and bow of the man to move together. */
class Man:public Composite
{
    Circle *head;
    Body *body;
    Bow *bow;
    public:
    Man(double x,double y,Color c,Composite* owner=NULL):Composite(x,y,owner)
    {
        head=new Circle (60,60,20,this);
        head->setColor(COLOR(255,206,180));
        head->setFill(c);
    }
    void forward(double d,bool repaintP=true)
    {
        forward(d,false);
        if(repaintP)
        repaint();
    }
};

//balloon code here : inheritance concept used
class Balloon:public Composite
{
    Circle *balloon1,*balloon2,*balloon3,*balloon4,*balloon5,*balloon6,*balloon7,*balloon8,*balloon9,*balloon10;
    Line *line11,*line12,*line13,*line14,*line21,*line22,*line23,*line24,*line25,*line31,*line32,*line33,*line34,*line41,*line42,*line43,*line44,
    *line51,*line52,*line53,*line54,*line71,*line72,*line73,*line74,*line91,*line92,*line93,*line94;
    int r=22,red=255,green=255,blue=255;
    public:
    Balloon(double x,double y,Composite*owner=NULL):Composite(x,y,owner)
    {
             balloon1=new Circle (600,103,r,this);
             balloon1->setColor(COLOR(144,238,144));
             balloon1->setFill(COLOR(144,238,144));

             line11=new Line (600,125,600,183,this);//body
             line11->setColor(COLOR(144,238,144));
             line11->setFill(COLOR(144,238,144));
             line12=new Line (600,150,580,175,this);//leg
             line12->setColor(COLOR(144,238,144));
             line12->setFill(COLOR(144,238,144));
             line13=new Line (600,128,565,128,this);//hand
             line13->setColor(COLOR(144,238,144));
             line13->setColor(COLOR(144,238,144));
             line14=new Line (565,128,562,130,this);//palm
             line14->setColor(COLOR(144,238,144));
             line14->setColor(COLOR(144,238,144));

             balloon2=new Circle (600,263,r,this);
             balloon2->setColor(COLOR(255,255,255));
             balloon2->setFill(COLOR(255,255,255));

             line21=new Line (610,280,648,340,this);//1st Human Hostage
             line21->setColor(COLOR(144,238,144));
             line21->setFill(COLOR(144,238,144));
             line22=new Line (648,341,670,338,this);//leg1
             line22->setColor(COLOR(144,238,144));
             line22->setFill(COLOR(144,238,144));
             line23=new Line (632,320,610,349,this);//leg2
             line23->setColor(COLOR(144,238,144));
             line23->setColor(COLOR(144,238,144));
             line24=new Line (614,290,590,308,this);//Arm 1
             line24->setColor(COLOR(144,238,144));
             line24->setColor(COLOR(144,238,144));
             line25=new Line (590,308,580,280,this);//
             line25->setColor(COLOR(144,238,144));
             line25->setColor(COLOR(144,238,144));
             line24=new Line (614,290,640,270,this);//Arm 2
             line24->setColor(COLOR(144,238,144));
             line24->setColor(COLOR(144,238,144));
             line25=new Line (640,270,660,308,this);//
             line25->setColor(COLOR(144,238,144));
             line25->setColor(COLOR(144,238,144));

             balloon3=new Circle (250,423,r,this);
             balloon3->setColor(COLOR(144,238,144));
             balloon3->setFill(COLOR(144,238,144));

             line31=new Line (250,445,250,503,this);//2nd zombie body
             line31->setColor(COLOR(144,238,144));
             line31->setFill(COLOR(144,238,144));
             line32=new Line (250,470,230,495,this);//leg
             line32->setColor(COLOR(144,238,144));
             line32->setFill(COLOR(144,238,144));
             line33=new Line (250,448,215,448,this);//hand
             line33->setColor(COLOR(144,238,144));
             line33->setColor(COLOR(144,238,144));
             line34=new Line (215,448,212,450,this);//palm
             line34->setColor(COLOR(144,238,144));
             line34->setColor(COLOR(144,238,144));

             balloon4=new Circle (900,555,r,this);
             balloon4->setColor(COLOR(144,238,144));
             balloon4->setFill(COLOR(144,238,144));

             line41=new Line (900,577,900,635,this);//3rd zombie body
             line41->setColor(COLOR(144,238,144));
             line41->setFill(COLOR(144,238,144));
             line42=new Line (900,602,880,627,this);//leg
             line42->setColor(COLOR(144,238,144));
             line42->setFill(COLOR(144,238,144));
             line43=new Line (900,580,865,580,this);//hand
             line43->setColor(COLOR(144,238,144));
             line43->setColor(COLOR(144,238,144));
             line44=new Line (865,580,862,582,this);//palm
             line44->setColor(COLOR(144,238,144));
             line44->setColor(COLOR(144,238,144));

             balloon5=new Circle (340,343,r,this);
             balloon5->setColor(COLOR(144,238,144));
             balloon5->setFill(COLOR(144,238,144));

             line51=new Line (340,365,340,423,this);//4th zombie body
             line51->setColor(COLOR(144,238,144));
             line51->setFill(COLOR(144,238,144));
             line52=new Line (340,390,320,415,this);//leg
             line52->setColor(COLOR(144,238,144));
             line52->setFill(COLOR(144,238,144));
             line53=new Line (340,368,305,368,this);//hand
             line53->setColor(COLOR(144,238,144));
             line53->setColor(COLOR(144,238,144));
             line54=new Line (305,368,302,370,this);//palm
             line54->setColor(COLOR(144,238,144));
             line54->setColor(COLOR(144,238,144));

             balloon6=new Circle (720,503,r,this);
             balloon6->setColor(COLOR(255,255,255));
             balloon6->setFill(COLOR(255,255,255));
             balloon7=new Circle (400,183,r,this);
             balloon7->setColor(COLOR(144,238,144));
             balloon7->setFill(COLOR(144,238,144));

             line71=new Line (400,205,400,263,this);//5th zombie body
             line71->setColor(COLOR(144,238,144));
             line71->setFill(COLOR(144,238,144));
             line72=new Line (400,230,380,255,this);//leg
             line72->setColor(COLOR(144,238,144));
             line72->setFill(COLOR(144,238,144));
             line73=new Line (400,208,365,208,this);//hand
             line73->setColor(COLOR(144,238,144));
             line73->setColor(COLOR(144,238,144));
             line74=new Line (365,208,362,210,this);//palm
             line74->setColor(COLOR(144,238,144));
             line74->setColor(COLOR(144,238,144));

             balloon8=new Circle (500,463,r,this);
             balloon8->setColor(COLOR(255,255,255));
             balloon8->setFill(COLOR(255,255,255));
             balloon9=new Circle (600,543,r,this);
             balloon9->setColor(COLOR(144,238,144));
             balloon9->setFill(COLOR(144,238,144));

             line91=new Line (600,565,600,623,this);//6th zombie body
             line91->setColor(COLOR(144,238,144));
             line91->setFill(COLOR(144,238,144));
             line92=new Line (600,590,580,615,this);//leg
             line92->setColor(COLOR(144,238,144));
             line92->setFill(COLOR(144,238,144));
             line93=new Line (600,568,565,568,this);//hand
             line93->setColor(COLOR(144,238,144));
             line93->setColor(COLOR(144,238,144));
             line94=new Line (565,568,562,570,this);//palm
             line94->setColor(COLOR(144,238,144));
             line94->setColor(COLOR(144,238,144));

             balloon10=new Circle (800,223,r,this);
             balloon10->setColor(COLOR(255,255,255));
             balloon10->setFill(COLOR(255,255,255));


    }
/*    void effects()
    {
         balloon1->scale(2);balloon1->scale(.5);
         balloon2->scale(2);balloon2->scale(.5);
         balloon3->scale(2);balloon3->scale(.5);
         balloon4->scale(2);balloon4->scale(.5);
         balloon5->scale(2);balloon5->scale(.5);
         balloon6->scale(2);balloon6->scale(.5);
         balloon7->scale(2);balloon7->scale(.5);
         balloon8->scale(2);balloon8->scale(.5);
         balloon9->scale(2);balloon9->scale(.5);
         balloon10->scale(2);balloon10->scale(.5);
    }*/
/*
    score_delete ---> used to update scores,balloon effect,and balloon hide upon arrow hit
    Logic used   ---> when y-coordinate of the moving arrow matches with the balloon y coordinate it is a hit
    flags help in keeping check that repeated balloon scores are not added.
*/
    void score_delete(int y)
    {


        if(y==63)//balloon 1
        {
            flag[0]=flag[0]+1;
            if(flag[0]==1)
            {
                score=score+20;
                balloon1->scale(2);
                balloon1->hide();
                line11->hide();
                line12->hide();
                line13->hide();
                line14->hide();
            }
        }
        if(y==223)//balloon 4
        {
           flag[1]=flag[1]+1;
            if(flag[1]==1)
            {
                score=score-10;
                balloon2->scale(2);
                balloon2->hide();
            }
        }
        if(y==383)//balloon 6
        {
            flag[2]=flag[2]+1;
            if(flag[2]==1)
            {
                score=score+20;
                balloon3->scale(2);
                balloon3->hide();
                line31->hide();
                line32->hide();
                line33->hide();
                line34->hide();
            }
        }
        if(y==543)//balloon 10
        {
            flag[3]=flag[3]+1;
            if(flag[3]==1)
            {
                score=score+20;
                balloon4->scale(2);
                balloon4->hide();
                line41->hide();
                line42->hide();
                line43->hide();
                line44->hide();
            }
        }
        if(y==303)//balloon 5
        {
            flag[4]=flag[4]+1;
            if(flag[4]==1)
            {
                score=score+20;
                balloon5->scale(2);
                balloon5->hide();
                line51->hide();
                line52->hide();
                line53->hide();
                line54->hide();
            }
        }
        if(y==463)//balloon 8
        {
            flag[5]=flag[5]+1;
            if(flag[5]==1)
            {
                score=score-10;
                balloon6->scale(2);
                balloon6->hide();
            }
        }
        if(y==143) //balloon 2
        {
            flag[6]=flag[6]+1;
            if(flag[6]==1)
            {
                score=score+20;
                balloon7->scale(2);
                balloon7->hide();
                line71->hide();
                line72->hide();
                line73->hide();
                line74->hide();
            }
        }
        if(y==423)//balloon 7
        {
            flag[7]=flag[7]+1;
            if(flag[7]==1)
            {
                score=score-10;
                balloon8->scale(2);
                balloon8->hide();
            }
        }
        if(y==503)//balloon 9
        {
            flag[8]=flag[8]+1;
            if(flag[8]==1)
            {
                score=score+20;
                balloon9->scale(2);
                balloon9->hide();
                line91->hide();
                line92->hide();
                line93->hide();
                line94->hide();
            }
        }
        if(y==183)//balloon 3
        {
            flag[9]=flag[9]+1;
            if(flag[9]==1)
            {
                score=score-10;
                balloon10->scale(2);
                balloon10->hide();
            }
        }
    }
};

/*This is the function by which the entire game is controlled */
int game()
{
    Rectangle BG(0,0,4000,2000);
    BG.setColor(COLOR(0,0,60));
    BG.setFill(COLOR(255,255,255));
    Man m(57,78,COLOR(255,255,0));
    Body b1(58,78,COLOR(255,255,0));
    Bow b2(57,79,COLOR(255,255,0));
    score=0;
    Arrow a1(15,103);//static arrow attached to man
    Arrow a2(0,0);//dynamic arrow(movable arrow)
    Text text1(a2.getX()+55,a2.getY()+78,"WELCOME");
    wait(0.2);
    text1.hide();
    a2.hide();
    double x=a1.getX(),y=a1.getY(),arrowcount=0;
    Balloon ball(250,50);

/*
                                        *Game controls
                            Used to display arrows left,Used to display current score
        Logic Used:Arrow release takes place from current location with the help of co-ordinates of static arrow
*/
/*THE GAME IS CONTROLLED BY THE COUNT OF THE ARROWS.
AFTER 6 ARROWS ARE USED THE GAME ENDS AND U EXIT THE GAME AFTER THE SCORECARD IS DISPLAYED*/
    while(arrowcount<6)
    {
        Text ending1(55,65,"Arrowcount");
        Text ending(55,79,char(6-arrowcount));
        Text board(120,65,"SCORE");
        Text sc(110,79,char(score));
        ending.scale(22);
        XEvent e;
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
        switch(ev)//SWITCH CASE USED FOR THE CONTROLLED MOVEMENT OF THE MAN(UP AND DOWN) AND TO SHOOT THE ARROW
        {
            case 'w':case 'W':
                m.move(0,-40);
                b1.move(0,-40);
                b2.move(0,-40);
                a1.move(0,-40);
                x=a1.getX();
                y=a1.getY();
//              ball.effects();
                break;
            case 'a':case 'A':
                m.move(-40,0);
                b1.move(-40,0);
                b2.move(-40,0);
                a1.move(-40,0);
                x=a1.getX();
                y=a1.getY();
                break;
            case 'd':case 'D':
                m.move(40,0);
                b1.move(40,0);
                b2.move(40,0);
                a1.move(40,0);
                x=a1.getX();
                y=a1.getY();
                break;
            case 's':case'S':
                m.move(0,40);
                b1.move(0,40);
                b2.move(0,40);
                a1.move(0,40);
                x=a1.getX();
                y=a1.getY();
//              ball.effects();
                break;
            case 'x':case 'X':
                a2.movement(x,y);
                arrowcount++;
                ball.score_delete(y);
                break;
            case 'p':case 'P':
                menu();
                break;
        }
    }
    if(arrowcount==6)
    {
        scorecard();
    }
    return(0);
}

main_program//MAIN FUNTION OF THE PROGRAM
{
    initCanvas("CPPDeamons Archery ", 1300, 900);//CREATION OF CANVAS
    load();//START LOAD SCREEN
    start_screen();//DISPLAY START SCREEN
}
