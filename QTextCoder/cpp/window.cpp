#include "include/window.h"

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{
    init();
    connectWidget();
}
void Window::connectWidget(){
    connect(clear,      &QPushButton::clicked, this, &Window::clearText     );
    connect(bin,        &QPushButton::clicked, this, &Window::toBin         );
    connect(dec,        &QPushButton::clicked, this, &Window::toDec         );
    connect(hex,        &QPushButton::clicked, this, &Window::toHex         );
    connect(replace,    &QPushButton::clicked, this, &Window::replaceText   );
    connect(fbin,       &QPushButton::clicked, this, &Window::fromBin       );
    connect(fdec,       &QPushButton::clicked, this, &Window::fromDec       );
    connect(fhex,       &QPushButton::clicked, this, &Window::fromHex       );
}

void Window::clearText(){
    output->clear();
    input->clear();
}

void Window::replaceText(){
    QString t1 = input->text();
    QString t2 = output->toPlainText();

    input->setText(t2);
    output->setText(t1);
}

void Window::toBin(){
    output->setText(binary->encode(input->text()));
}

void Window::toDec(){
    output->setText(decimal->encode(input->text()));
}

void Window::toHex(){
    output->setText(hexadecimal->encode(input->text()));
}

void Window::fromBin(){
    output->setText(binary->decode(input->text()));
}

void Window::fromDec(){
    output->setText(decimal->decode(input->text()));
}

void Window::fromHex(){
    output->setText(hexadecimal->decode(input->text()));
}

void Window::init(){
    ui = new QWidget(this);
    l0 = new QVBoxLayout(this);
    l1 = new QHBoxLayout(this);
    l2 = new QHBoxLayout(this);
    l3 = new QHBoxLayout(this);
    l4 = new QHBoxLayout(this);
    input  = new QLineEdit(this);
    output = new QTextEdit(this);
    clear = new QPushButton("Clear");
    bin = new QPushButton("To Bin");
    dec = new QPushButton("To Dec");
    hex = new QPushButton("To Hex");
    replace = new QPushButton("Replace");
    fbin = new QPushButton("From Bin");
    fdec = new QPushButton("From Dec");
    fhex = new QPushButton("From Hex");
    l1 -> addWidget(input);
    l4 -> addWidget(clear);
    l4 -> addWidget(replace);
    l2 -> addWidget(bin);
    l2 -> addWidget(dec);
    l2 -> addWidget(hex);
    l3 -> addWidget(fbin);
    l3 -> addWidget(fdec);
    l3 -> addWidget(fhex);
    l0 -> addLayout(l1);
    l0 -> addLayout(l4);
    l0 -> addLayout(l2);
    l0 -> addLayout(l3);
    l0 -> addWidget(output);
    ui -> setLayout(l0);
    setCentralWidget(ui);

    binary = new BinaryCoder();
    decimal = new DecimalCoder();
    hexadecimal = new HexCoder();
}

Window::~Window()
{
    delete ui;
    delete l0;
    delete l1;
    delete l2;
    delete input ;
    delete output;
    delete clear ;
    delete bin ;
    delete dec ;
    delete hex ;
}

