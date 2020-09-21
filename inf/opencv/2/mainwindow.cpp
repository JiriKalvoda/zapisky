#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
            QString nazevSouboru = QFileDialog::getOpenFileName();
            //nacteni souboru z disku do promenne typu cv::Mat
            //nazev typu QString je nutno převest do typu string
            image = cv::imread(cv::String(nazevSouboru.toStdString()));
            reloadLabel();

}

void MainWindow::on_actionSave_triggered()
{
            QString nazevSouboru = QFileDialog::getSaveFileName();
            //ulozeni matice do souboru na disk
            //nazev typu QString je nutno převest do typu string
            cv::imwrite(cv::String(nazevSouboru.toStdString()), image);

}

void MainWindow::reloadLabel()
{
            //pomocna matice pro konverzi barev
            cv::Mat dest;
            //konverze barev pro QT (z BGR do RGB)
            cv::cvtColor(image, dest, cv::COLOR_BGR2RGB);
            //vytvoreni rastroveho obrazku pro QT z pomocne matice
            QImage image2 = QImage((uchar*) dest.data, dest.cols, dest.rows, dest.step, QImage::Format_RGB888);
            //nastaveni obrazku u QLabelu
            ui->label->setPixmap(QPixmap::fromImage(image2));

}
void MainWindow::on_actionCircle_triggered()
{
    //nakresleni kruznice
    //parametry
    // 1: obrazek v matici
    // 2: stred kruznice
    // 3: polomer
    // 4: barva RGB
    // 5: tloustka cary
    int sirka = image.size().width;
    int vyska = image.size().height;
    int minimum = (sirka<vyska)?sirka:vyska;
    cv::circle(image, cv::Point(sirka/2,vyska/2), minimum/2, cv::Scalar(255,0,0),5);
    reloadLabel();
}

void MainWindow::on_actionRectangle_triggered()
{
    int sirka = image.size().width;
    int vyska = image.size().height;
    cv::rectangle(image,{10,10},{sirka-10,vyska-10},cv::Scalar(100,200,100),8);
    reloadLabel();

}

void MainWindow::on_Take_clicked()
{
        //definice objektu videokamery, parametr určuje pořadové číslo vybrané kamery
        //aktivace kamery na mém počítači trvá i několik desítek sekund!?!?
        //a jak dlouho bude trvat u vás?
        cv::VideoCapture cap("/dev/video0");
        //načtení obrázku z kamery do matice
        cap >> image;
        //pokud je matice prázdná
        //if (!image.data)
        //{
            //qDebug("ERROR");
            //return;
        //}
        reloadLabel();
}
// funkce detectFaces byla ukradena z tutorialu na adrese
// https://docs.opencv.org/master/db/d28/tutorial_cascade_classifier.html
// mírně jsem ji upravil, abych ji přzpůsobil podmínkám v naší aplikaci
void detectFaces(cv::Mat frame)
{
    //objekt pro detekci všeho, co jej naučíte (tento máme pro obličeje)
    cv::CascadeClassifier face_cascade;
    //objekt pro detekci všeho, co jej naučíte (tento máme pro oči)
    cv::CascadeClassifier eyes_cascade;
    //objekt už za nás někdo naučil a "učební" data pro obličeje jsou
    //v souboru haarcascade_frontalface_alt.xml
    // !!!!!! cestu k souboru si nastavte dle vlastních podmínek !!!!!!
    // pro Windows bude vypadat např. nějak takto:
    // if(!face_cascade.load("C:\\Users\\marba\\opencv\\detekce\\haarcascade_frontalface_alt.xml"))
    // příslušný soubor si XML si stáhněte z Moodlu
    if(!face_cascade.load("haarcascade_frontalface_alt.xml")
    || !eyes_cascade.load("haarcascade_eye_tree_eyeglasses.xml"))
    {
        QMessageBox::critical(0,"","Data error");
        return;
    };
    //pro správnou funkci detekce se matice s původním barevným obrázkem
    //převádí do 256 stupňů šedi
    cv::Mat frame_gray;
    cv::cvtColor( frame, frame_gray, cv::COLOR_BGR2GRAY );
    cv::equalizeHist( frame_gray, frame_gray );
    //vlastní detekce obličejů
    std::vector<cv::Rect> faces;//něco jako pole obdélníků (tzv. vector)
    face_cascade.detectMultiScale( frame_gray, faces );//vytvoření obdélníků v místech s obličeji
    //zakreslení kružnic kolem každého obličeje
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        cv::Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        cv::ellipse( frame, center, cv::Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4 );
        cv::Mat faceROI = frame_gray( faces[i] );
        //detekce očí pro každý obličej
        std::vector<cv::Rect> eyes;
        eyes_cascade.detectMultiScale( faceROI, eyes );
        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            cv::Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, cv::Scalar( 255, 0, 0 ), 4 );
        }
    }
}

void MainWindow::on_FindFace_clicked()
{
    //pokud máme v obrázku nějaká data
    if (image.data)
    {
        //funkce detectFaces v matici image provede označení obličejů
        //původní obrázek v image je změněn tak, že jsou do něj dokresleny
        //kružnice kolem obličejů
        detectFaces(image);
        reloadLabel();
    }
}
