#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMainWindow>

#include <bitset>
#include <cmath>

class MainActivity : public QMainWindow {
 public:
        MainActivity(QMainWindow *parent = 0)  : QMainWindow(parent) {
              calcBtn = new QPushButton("Convert", this);
              clear = new QPushButton("Clear", this);
              text = new QLabel();
              editText = new QLineEdit();
          QGridLayout *grid = new QGridLayout(this);
              grid->addWidget(editText, 0, 0);
              grid->addWidget(calcBtn, 0, 1);
              grid->addWidget(text, 1, 0);
              grid->addWidget(clear,1,1);

              QWidget *layout = new QWidget(this);
              layout->setLayout(grid);
              setCentralWidget(layout);

             quitAction            = new QAction("&Quit", this);
             clearAction           = new QAction("&Clear", this);
             checkTextAction  = new QAction("&Check Text", this);
             aboutAction         = new QAction("&About", this);

             checkTextAction->setCheckable(true);
             checkTextAction->setChecked(false);

           QMenu *app = menuBar()->addMenu("&App");
           app->addAction(checkTextAction);
           app->addAction(clearAction);

           QMenu *info = menuBar()->addMenu("&Info");
           info->addAction(aboutAction);
           info->addSeparator();
           info->addAction(quitAction);


             connect(checkTextAction, &QAction::triggered, this, &MainActivity::calcChecked);
             connect(quitAction, &QAction::triggered, &QApplication::quit);
             connect(clearAction, &QAction::triggered, this, &MainActivity::clean);
             connect(aboutAction, &QAction::triggered, this, &MainActivity::showInfo);

              connect(calcBtn,  &QPushButton::clicked ,  this,  &MainActivity::calc);
              connect(editText,  &QLineEdit::returnPressed ,  this,  &MainActivity::calc);
              connect(clear,  &QPushButton::clicked ,  this,  &MainActivity::clean);
        }
    private slots:
            void clean(){
                text->setText(nullptr);
                editText->setText(nullptr);
            }
            void showInfo(){
                QMessageBox msgBox;

                QString text[5];

                text[0] = "Convert any numbers from -2^32 to 2^32. \n";
                text[1] = "                     Esc or Q to Exit \n";
                text[2] = "               C for clean text fields \n";
                text[3] = "          Created by Maks Makuta \n";
                text[4] = "                          2020 \n";

                msgBox.setText("Binary Converter v.1.0");
                msgBox.setInformativeText( text[0] + text[1] + text[2] + text[3] + text[4] );
                   msgBox.setStandardButtons(QMessageBox::Ok);
                   msgBox.setDefaultButton(QMessageBox::Ok);
                   int ret = msgBox.exec();
                   if(ret==QMessageBox::Ok)
                    msgBox.close();
                   else
                    exit(0);
            }
            void calcChecked(){
                if(checkTextAction->isEnabled()){
                    connect(editText,  &QLineEdit::textChanged, this, &MainActivity::calc);
                }
            }
            void calc(){
                QString txt;
                if(editText->text() == nullptr){
                    txt = "   ";
                }else{
                long data = QString(editText->text()).toLong();
                    if(data > LONG_MIN && data < LONG_MAX){
                        std::string str = std::bitset<32>(data).to_string();
                        txt = str.c_str();
                    }else{
                        txt = "Your number more than (+/-)2^32"; //TODO make show this message
                    }
                }
                text->setText(txt);
            }
    protected:
       void keyPressEvent(QKeyEvent * e){
           switch (e->key()) {
               case Qt::Key_Q:
               case Qt::Key_Escape:
                    qApp->quit();
                   break;

               case Qt::Key_C:
                   clean();
                   break;

               default:
                   break;
           }
       }
    private:
             QPushButton *calcBtn, *clear;
             QLabel *text;
             QLineEdit *editText;
             QAction  *quitAction ,*clearAction,*checkTextAction,*aboutAction;
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  MainActivity window;
  window.setFixedSize(300,100);
  window.setWindowTitle("BinaryConverter");
  window.show();
  return app.exec();
}
