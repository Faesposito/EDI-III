#include <iostream>

// Button Class
class Button
{
public:
    virtual void paint() = 0;
};

class WinButton : public Button
{
public:
    void paint()
    {
        std::cout << " Window Button \n";
    }
};

class MacButton : public Button
{
public:
    void paint()
    {
        std::cout << " Mac Button \n";
    }
};

class iPhoneButton : public Button
{
public:
    void paint()
    {
        std::cout << " iPhone Button \n";
    }
};

// ScrollBar Class
class ScrollBar
{
public:
    virtual void paint() = 0;
};

class WinScrollBar : public ScrollBar
{
public:
    void paint()
    {
        std::cout << " Window ScrollBar \n";
    }
};

class MacScrollBar : public ScrollBar
{
public:
    void paint()
    {
        std::cout << " Mac ScrollBar \n";
    }
};

class iPhoneScrollBar : public ScrollBar
{
public:
    void paint()
    {
        std::cout << " iPhone ScrollBar \n";
    }
};

// Abstract Factory Class

class GUIFactory
{
public:
    virtual Button *createButton() = 0;
    virtual ScrollBar *createScrollBar() = 0;
};

class WinFactory : public GUIFactory
{
public:
    Button *createButton()
    {
        return new WinButton;
    }
    ScrollBar *createScrollBar()
    {
        return new WinScrollBar;
    }
};

class MacFactory : public GUIFactory
{
public:
    Button *createButton()
    {
        return new MacButton;
    }
    ScrollBar *createScrollBar()
    {
        return new MacScrollBar;
    }
};

class iPhoneFactory : public GUIFactory
{
public:
    Button *createButton()
    {
        return new iPhoneButton;
    }
    ScrollBar *createScrollBar()
    {
        return new iPhoneScrollBar;
    }
};

int main()
{
    GUIFactory *guiFactory;
    Button *button;
    ScrollBar *scrollbar;

    guiFactory = new MacFactory;
    button = guiFactory->createButton();
    button->paint();
    scrollbar = guiFactory->createScrollBar();
    scrollbar->paint();

    guiFactory = new WinFactory;
    button = guiFactory->createButton();
    button->paint();
    scrollbar = guiFactory->createScrollBar();
    scrollbar->paint();

    guiFactory = new iPhoneFactory;
    button = guiFactory->createButton();
    button->paint();
    scrollbar = guiFactory->createScrollBar();
    scrollbar->paint();

    return 0;
}