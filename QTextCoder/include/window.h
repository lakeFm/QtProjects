#ifndef WINDOW_H
#define WINDOW_H

#include "binarycoder.h"
#include "decimalcoder.h"
#include "hexcoder.h"

#include <QHBoxLayout>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void clearText();
    void toBin();
    void toDec();
    void toHex();
    void replaceText();
    void fromBin();
    void fromDec();
    void fromHex();


private:
    void init();
    void connectWidget();

    QWidget *ui;
    QHBoxLayout *l1 , *l2 ,*l3 , *l4;
    QVBoxLayout *l0;
    QLineEdit *input;
    QTextEdit *output;
    QPushButton *clear, *bin, *dec, *hex, *fbin, *fdec, *fhex,*replace;

    BinaryCoder *binary;
    DecimalCoder *decimal;
    HexCoder *hexadecimal;

};
#endif // WINDOW_H
