#include "interface.h"
#include "polinom.h"
TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №3");
    setFixedSize(300,250);
    name_a = new QLabel("a =",this);
    name_a->setGeometry(40,20,30,25);
    a_chi = new QLineEdit("1",this);
    a_chi->setGeometry(90,20,50,25);
    delimeter_a = new QLabel("/",this);
    delimeter_a->setGeometry(150,20,30,25);
    a_zm = new QLineEdit("1",this);
    a_zm->setGeometry(165,20,50,25);

    name_b = new QLabel("b =",this);
    name_b->setGeometry(40,50,30,25);
    b_chi = new QLineEdit("1",this);
    b_chi->setGeometry(90,50,50,25);
    delimeter_b = new QLabel("/",this);
    delimeter_b->setGeometry(150,50,30,25);
    b_zm = new QLineEdit("1",this);
    b_zm->setGeometry(165,50,50,25);

    name_c = new QLabel("c =",this);
    name_c->setGeometry(40,80,30,25);
    c_chi = new QLineEdit("1",this);
    c_chi->setGeometry(90,80,50,25);
    delimeter_c = new QLabel("/",this);
    delimeter_c->setGeometry(150,80,30,25);
    c_zm = new QLineEdit("1",this);
    c_zm->setGeometry(165,80,50,25);

    name_x = new QLabel("x =",this);
    name_x->setGeometry(40,110,30,25);
    x_chi = new QLineEdit("1",this);
    x_chi->setGeometry(90,110,50,25);
    delimeter_x = new QLabel("/",this);
    delimeter_x->setGeometry(150,110,30,25);
    x_zm = new QLineEdit("1",this);
    x_zm->setGeometry(165,110,50,25);

    roots_btn = new QPushButton ("roots",this);
    roots_btn->setGeometry(20,150,60,30);
    value_btn = new QPushButton ("value",this);
    value_btn->setGeometry(90,150,60,30);
    print_classic_btn = new QPushButton ("classic",this);
    print_classic_btn->setGeometry(160,150,60,30);
    print_canonic_btn = new QPushButton ("canonic",this);
    print_canonic_btn->setGeometry(230,150,60,30);

    output = new QLabel(this);
    output->setGeometry(10,200,280,25);

    connect(value_btn,SIGNAL(pressed()),this,SLOT(value()));
    connect(print_classic_btn,SIGNAL(pressed()),this,SLOT(print_classic()));
    connect(print_canonic_btn, SIGNAL(pressed()),this,SLOT(print_canonic()));
    connect(roots_btn, SIGNAL(pressed()),this,SLOT(roots()));
}

TInterface::~TInterface()
{
    delete name_a;
    delete a_chi;
    delete delimeter_a;
    delete a_zm;

    delete name_b;
    delete b_chi;
    delete delimeter_b;
    delete b_zm;

    delete name_c;
    delete c_chi;
    delete delimeter_c;
    delete c_zm;

    delete name_x;
    delete x_chi;
    delete delimeter_x;
    delete x_zm;

    delete value_btn;
    delete roots_btn;
    delete print_classic_btn;
    delete print_canonic_btn;

    delete output;

}
void TInterface::value()

{
    QString s("");
    if (a_zm->text().toInt()==0 || b_zm->text().toInt()==0 || c_zm->text().toInt()==0 || x_zm->text().toInt()==0)
    {
        s += "Denominator < 0!";
    }
    else
    {
        if (a_chi->text().toInt()==0)
        {
            s += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(a_chi->text().toInt(),a_zm->text().toInt());
            number b(b_chi->text().toInt(),b_zm->text().toInt());
            number c(c_chi->text().toInt(),c_zm->text().toInt());
            TPolinom p(a, b, c);
            number x(x_chi->text().toInt(),x_zm->text().toInt());
            number v = p.value(x);
            s+="p=";
            s << x;
            s += "=";
            s << v;
        }

    }
    output->setText(s);
}
void TInterface::print_classic()

{
    QString s("");
    if (a_zm->text().toInt()==0 || b_zm->text().toInt()==0 || c_zm->text().toInt()==0 || x_zm->text().toInt()==0)
    {
        s += "Denominator < 0!";
    }
    else
    {
        if (a_chi->text().toInt()==0)
        {
            s += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(a_chi->text().toInt(),a_zm->text().toInt());
            number b(b_chi->text().toInt(),b_zm->text().toInt());
            number c(c_chi->text().toInt(),c_zm->text().toInt());
            TPolinom p(a, b, c);
            p.setPrintMode(EPrintModeClassic);
            s+="p(x)=";
            s<<p;
        }

    }
    output->setText(s);
}
void TInterface::print_canonic()
{
    QString s("");
    if (a_zm->text().toInt()==0 || b_zm->text().toInt()==0 || c_zm->text().toInt()==0 || x_zm->text().toInt()==0)
    {
        s += "Denominator < 0!";
    }
    else
    {
        if (a_chi->text().toInt()==0)
        {
            s += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(a_chi->text().toInt(),a_zm->text().toInt());
            number b(b_chi->text().toInt(),b_zm->text().toInt());
            number c(c_chi->text().toInt(),c_zm->text().toInt());
            TPolinom p(a, b, c);
            number* roots = p.calculateRoots ();
            if(roots!=NULL)
            {
                p.setPrintMode(EPrintModeCanonic);
                s+="p(x)=";
                s<<p;
            }
            else
            {
                    s += "The equation has no solution!";
            }
            free(roots);
        }
    }
    output->setText(s);
}
void TInterface::roots()
{
    QString s("");
    if (a_zm->text().toInt()==0 || b_zm->text().toInt()==0 || c_zm->text().toInt()==0 || x_zm->text().toInt()==0)
    {
        s += "Denominator < 0!";
    }
    else
    {
        if (a_chi->text().toInt()==0)
        {
            s += "The coefficient a cannot be zero!";
        }
        else
        {
            number a(a_chi->text().toInt(),a_zm->text().toInt());
            number b(b_chi->text().toInt(),b_zm->text().toInt());
            number c(c_chi->text().toInt(),c_zm->text().toInt());
            TPolinom p(a, b, c);
            number* roots = p.calculateRoots ();
            if(roots!=NULL)
            {
                    s+="x1=";
                    s<<roots[0];
                    s+="; x2=";
                    s<<roots[1];
                    s+=";";
            }
            else
            {
                    s += "The equation has no solution!";

            }
            free(roots);
        }

    }
    output->setText(s);
}
