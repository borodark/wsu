using namespace std;

Profile::Profile()
{
} // end constructor
Profile::Profile(const string name,const string picture, const Status status) : name(name), picture(picture), status(status), memberPtr(nullptr)
{
} // end constructor

Profile::~Profile(){
  cout << "Profile "<< name << " is destroyed!" << endl;
  memberPtr = nullptr;
} // end default constructor

void Profile::setMember(const TFBMember* aMemberPtr){
  memberPtr = aMemberPtr;
}

const string Profile::getName() const {
  return name;
}
void Profile::setName(string newOne){
  name = newOne;
}

const string Profile::getPicture() const {
  return picture;
}
void Profile::setPicture(string newOne){
  picture = newOne;
}
const Status Profile::getStatus() const {
  return status;
}
void Profile::setStatus(Status newOne){
  status = newOne;
}
const bool Profile::isMember() const {
  return (memberPtr != nullptr);
}


const string Profile::print() const // 
{
  return " Profile: " + getName() +
    " -> " + getPicture() +
    " -> " + statuses[getStatus()] +
    " -> is member: " + (isMember()? "Y":"N");
}

// TODO Accessors, print , etc 

