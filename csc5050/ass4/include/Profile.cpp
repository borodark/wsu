using namespace std;

Profile::Profile()
{
} // end constructor
Profile::Profile(const string name,const string picture, const Status status) : name(name), picture(picture), status(status), memberPtr(nullptr)
{
} // end constructor

void Profile::setMember(const Node* aMemberPtr){
  memberPtr = aMemberPtr;
}

const string Profile::getName() const {
  return name;
}
const string Profile::getPicture() const {
  return picture;
}
const Status Profile::getStatus() const {
  return status;
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

