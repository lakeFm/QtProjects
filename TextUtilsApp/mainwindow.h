#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr): QMainWindow(parent){
          init();
        }


        ~MainWindow(){
            delete ui;
            delete inputText;
            delete clearBtn;
            delete reverseBtn;
            delete inverseBtn;
            delete outText;
        }


private slots:
        void clear(){
            inputText->clear();
        }

        void reverse(){
            QString text = inputText->text();
            QString reversed;
            for(QChar c: text){
                reversed.push_front(c);
            }

            outText->setText(reversed);
        }

        void inverse(){
            QString input =  inputText->text();

            if((QChar)input[input.size()] != ' '){
                input.push_back(" ");
            }

            QVector<QString> text = single_words( input);
            QString data;
            for(QString s: text){
                data.push_back(inverseWord(s));
                data.push_back(" ");
            }
            outText->setText(data);
        }

private:
    QLineEdit       *inputText;
    QPushButton     *clearBtn, *reverseBtn, *inverseBtn;
    QTextEdit       *outText;

    QWidget         *ui;

    QVector<QString> single_words(QString sentence)
    {
        QVector<QString> word_vector;
        QString result_word;

        for (int i = 0; i < sentence.size(); ++i)
        {
            QChar character = sentence[i];
            if (character == ' ' && result_word.size() != 0)
            {
                word_vector.push_back(result_word);
                result_word = "";
            }
            else
                result_word += character;
        }
        return word_vector;
    }

    QString inverseWord (QString in){
        QString inversed;
        for(QChar c: in){
            inversed.push_front(c);
        }
        return inversed;
    }

    void init(){
        QVBoxLayout *vLayout = new QVBoxLayout(this);
        QHBoxLayout * h1Layout = new QHBoxLayout(this);
        QHBoxLayout * h2Layout = new QHBoxLayout(this);
        QHBoxLayout * h3Layout = new QHBoxLayout(this);

        vLayout->addLayout(h1Layout);
        vLayout->addLayout(h2Layout);
        vLayout->addLayout(h3Layout);

        inputText = new QLineEdit(this);
        clearBtn = new QPushButton("Clear",this);

        h1Layout->addWidget(inputText);
        h1Layout->addWidget(clearBtn);

        reverseBtn = new QPushButton("Reverse All",this);
        inverseBtn = new QPushButton("Inverse By Words",this);

        h2Layout->addWidget(reverseBtn);
        h2Layout->addWidget(inverseBtn);

        outText = new QTextEdit(this);

        h3Layout->addWidget(outText);

        ui = new QWidget(this);
        ui->setLayout(vLayout);
        setCentralWidget(ui);

        connect(clearBtn,    &QPushButton::clicked ,  this,  &MainWindow::clear  );
        connect(reverseBtn,  &QPushButton::clicked ,  this,  &MainWindow::reverse);
        connect(inverseBtn,  &QPushButton::clicked ,  this,  &MainWindow::inverse);

    }
};
#endif // MAINWINDOW_H
