#include <iostream>
#include <string>

using namespace std;

// Dependency Inversion - Introduce Interfaces
// Interface segregation - reduce fat interfaces

class ICommunicationManager{
    public:
    virtual void shareContent(string imageLink) = 0;
};

class ImageGallery {
	string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","fiv.jpg"};
    int whichImage;
public:
    void share(int index, ICommunicationManager* comManager){ 
        comManager->shareContent(images[index]);
        }
};

class BluetoothManager : public ICommunicationManager {
public:
    void shareContent(string imageLink){
        cout << " share content: BluetoothManager" << endl ;
    }
	void searchDevices() {}
    void pairdevice(){}
	void sendContent() {}
	void turnOn() {}
	void turnOff(){}

};

class WhatsUpManager : public ICommunicationManager {
    public:
    void shareContent(string imageLink){
        cout << " share content: WhatsUpManager" << endl ;
    }
	void turnOn() {}
	void turnOff() {}
	void shareContent() {}
	void joinGroup() {}
	void addMember(){}
	void createGroup() {}


};

class MailManager : public ICommunicationManager {
    public:
    void shareContent(string imageLink){
        cout << " share content: MailManager" << endl ;
    }
	void pullNewMails() {}
	void senMails(){}
	void composeEmail(){}
	void addAttachement() {}

};

int main() {

	MailManager* _mailManager = new  MailManager();
	BluetoothManager* _bluetoothManager = new  BluetoothManager();
	WhatsUpManager* _whatsUpManager = new  WhatsUpManager();
	
	ImageGallery* imageMgmt = new  ImageGallery();
	imageMgmt->share(0, _mailManager);
    imageMgmt->share(0, _bluetoothManager);
    imageMgmt->share(0, _whatsUpManager);
	
}