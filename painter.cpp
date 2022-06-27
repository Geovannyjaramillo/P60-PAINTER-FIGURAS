#include "painter.h"
#include "ui_painter.h"

painter::painter(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::painter)
{
    ui->setupUi(this);
}

painter::~painter()
{
    delete ui;
}

void painter::paintEvent(QPaintEvent *event)
{
    //Crear el objeto painter, establecer el formulario como su lienzo
    QPainter pintor(this);

    //Establecer un color a su pincel
    pintor.setPen(Qt::blue);

    //Dibujar una linea
    pintor.drawLine(600, 100, 200,200); //los numeros representan coordenadas para que pueda dibujar

    //Cambiar el color del pincel
    pintor.setPen(Qt::red);

    //establecer un tipo y tamaño de letra
    pintor.setFont(QFont("Arial",30)); //30 pixeles, las letras se hacen mas grandes

    //Dibujar un texto
    pintor.drawText(250,150,"Picaso"); // x=250 y y=150

    //#################Crear un nuevo pincel######################
    QPen pincel;
    pincel.setColor(Qt::green);
    pincel.setWidth(10);
    pincel.setCapStyle(Qt::RoundCap);

    //Utilizar el nuevo pincel
    pintor.setPen(pincel);

    //Establecer una brocha
    pintor.setBrush(Qt::lightGray); //esto es para pintar el cuadrado

    //Dibujar un cuadrado
    pintor.drawRect(400,100,100,100);

    //Crear un nuevo color
    QColor miColor(255,221,129);//color RGB sacado de paletton, si añades 128 al final el circulo se hara mas transparente

    //#####################Crear un nuevo pincel####################
    QPen pincel2;
    pincel2.setColor(Qt::yellow);
    pincel2.setWidth(5);
    pincel2.setStyle(Qt::DotLine);

    //Establecer el nuevo pincel
    pintor.setPen(pincel2);

    //Cambiar la brocha
    pintor.setBrush(miColor);

    //Dibujar un circulo
    pintor.drawEllipse(550,100,100,100);

    //###################Crear nuevo pincel##########################
    QPen pincel3;
    pincel3.setColor(Qt::red);
    pincel3.setWidth(9);
    pincel3.setStyle(Qt::DotLine);

    //Usar en nuevo pincel
    pintor.setPen(pincel3);

    pintor.drawText(100,500,"Programacion");

    //Coordenadas para dibyjar una estrela
    QPolygon poly;

    poly << QPoint(0, 85) << QPoint(75, 75)
         << QPoint(100, 10) << QPoint(125, 75)
         << QPoint(200, 85) << QPoint(150, 125)
         << QPoint(160, 190) << QPoint(100, 150)
         << QPoint(40, 190) << QPoint(50, 125)\
         << QPoint(0, 85);
    QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
    pintor.setPen(pen);
    pintor.drawPolygon(poly);

    //un cuadrado con bordes redondos
    pintor.drawRoundedRect(QRect(10, 300, 100, 50), 10, 10);

    //ovalo
    pintor.drawRoundedRect(QRect(10, 400, 100, 50), 500, 500);

    //coordenadas para dibujar un Arco
    pintor.setRenderHint(QPainter::Antialiasing);
    pintor.scale(2, 2);
    pintor.translate(100, -100);
    pintor.rotate(25);
    pintor.drawArc(QRect(150, 50, 100, 100), 0, 180 * 16);
}

