#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Door {
public:
	virtual void open(){}
	virtual void close(){}
};

class IDoorStateNotifier{
	public:
	virtual void notify(string status) = 0;

};

class SecuredDoor : public Door{
	IDoorStateNotifier* notifierRef;
	public:
		SecuredDoor(IDoorStateNotifier* notifierArg): notifierRef{notifierArg}{}
		void open() override {
			this->notifierRef->notify("open");
		}
		void close() override {
			this->notifierRef->notify("close");
		}
};


class Buzzer : public IDoorStateNotifier {
	public:
		void notify(string status){
			cout << "Buzzer Notified! Door status is " << status << endl;
			this->makeNoise();
		}
		void makeNoise(){}
};

class  SMSManager : public IDoorStateNotifier {
	public :
	void notify(string status){
		cout << "SMSManager Notified! Door status is " << status << endl;
		this->sendNotificationMessage();
	}
	void sendNotificationMessage() {

	 }
};

class VisualizationManager : public IDoorStateNotifier{
	void notify(string status){
		cout << "VisualizationManager Notified! Door status is " << status << endl;
		this->turnVideoOn();
	}
	public:void turnVideoOn() {}
	public:void turnVideoOff() {}
};

class CompositeNotificationManagers: public IDoorStateNotifier{
	private:
	vector<IDoorStateNotifier*> notifiers;
	public:
		void addNotifier(IDoorStateNotifier* notifier){
			notifiers.push_back(notifier);
		}
		void notify(string status){
			for(auto notifier : notifiers){
				notifier->notify(status);
			}
		}
};
int main(){
	Buzzer buzzerObj;
	SMSManager smsObj;
	CompositeNotificationManagers cm;
	cm.addNotifier(&buzzerObj);
	cm.addNotifier(&smsObj);
	SecuredDoor newDoor {&cm};
	newDoor.open();
	newDoor.close();
	return 0;
}