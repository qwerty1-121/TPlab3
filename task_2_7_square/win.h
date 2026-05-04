#ifndef WIN_H
#define WIN_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

class Win : public QWidget
{
    Q_OBJECT

private:
    QFrame *frame;

    QLabel *inputLabel;
    QLineEdit *inputEdit;

    QLabel *outputLabel;
    QLineEdit *outputEdit;

    QPushButton *nextButton;
    QPushButton *exitButton;

public:
    explicit Win(QWidget *parent = nullptr);

public slots:
    void begin();
    void calc();
};

class StrValidator : public QValidator
{
public:
    explicit StrValidator(QObject *parent = nullptr)
        : QValidator(parent)
    {
    }

    State validate(QString &str, int &pos) const override
    {
        Q_UNUSED(str);
        Q_UNUSED(pos);

        return Acceptable;
    }
};

#endif // WIN_H