#include <QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    // Create Qt application
    QApplication app(argc, argv);
    
    // Create and show the dialog
    Dialog dialog;
    dialog.show();
    
    // Run the event loop
    return app.exec();
}