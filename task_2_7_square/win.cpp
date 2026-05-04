#include "win.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение числа в квадрат");

    frame = new QFrame(this);
    frame->setFrameStyle(QFrame::Box | QFrame::Raised);

    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit(this);

    StrValidator *validator = new StrValidator(inputEdit);
    inputEdit->setValidator(validator);

    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit(this);
    outputEdit->setReadOnly(true);

    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QVBoxLayout *frameLayout = new QVBoxLayout(frame);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(inputLabel);
    inputLayout->addWidget(inputEdit);

    QHBoxLayout *outputLayout = new QHBoxLayout();
    outputLayout->addWidget(outputLabel);
    outputLayout->addWidget(outputEdit);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(nextButton);
    buttonLayout->addWidget(exitButton);

    frameLayout->addLayout(inputLayout);
    frameLayout->addLayout(outputLayout);
    frameLayout->addLayout(buttonLayout);

    mainLayout->addWidget(frame);

    connect(inputEdit, SIGNAL(returnPressed()),
            this, SLOT(calc()));

    connect(nextButton, SIGNAL(clicked()),
            this, SLOT(begin()));

    connect(exitButton, SIGNAL(clicked()),
            this, SLOT(close()));

    begin();
}

void Win::begin()
{
    inputEdit->clear();
    outputEdit->clear();

    inputEdit->setEnabled(true);
    outputEdit->setEnabled(false);

    outputLabel->setVisible(false);
    outputEdit->setVisible(false);

    nextButton->setEnabled(false);

    inputEdit->setFocus();
}

void Win::calc()
{
    bool ok = false;
    double value = inputEdit->text().toDouble(&ok);

    if (ok)
    {
        double result = value * value;

        outputEdit->setText(QString::number(result));

        inputEdit->setEnabled(false);

        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        outputEdit->setEnabled(true);

        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else if (!inputEdit->text().isEmpty())
    {
        QMessageBox::information(this,
                                 "Ошибка ввода",
                                 "Нужно ввести число.");
    }
}