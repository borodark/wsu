using namespace std;

Profile::Profile()
{
} // end default constructor

Profile::Profile(const string name,const string picture, const Status status) : name(name), picture(picture), status(status), memberPtr(nullptr)
{
} // end constructor

const string Profile::getName(){
  return name;
}
const string Profile::getPicture(){
  return picture;
}
const Status Profile::getStatus(){
  return status;
}
const bool Profile::isMember(){
  return memberPtr != nullptr;
}

// TODO Accessors, print , etc 

