enum title
{
    JUNIOR,
    SENIOR
};
enum specialStatus
{
    NONE,
    PREGNANT
};
enum dayOffType
{
    WORKING,
    RED_LINE,
    GREEN_LINE,
    VACATION_RESERVATION
};
//https://tonybai.com/2012/09/26/interoperability-between-go-and-c/
//https://kknews.cc/zh-tw/other/p4pv3vz.html

struct Staff
{
    const char *name;
    const char *id;
    enum title position;
    enum specialStatus status;
    enum dayOffType askDayOff[31];
    int year; //for test
};

int greet(struct Staff *g, char *out);
int getArray(int *arr, int size, char *out);
int getInt(int number, char *out);

void PrintArray(int arr[], int len);
int *CreateArray(int len);
void SetArrValue(int *arr, int index, int value);

struct Staff *CreateStaffs(int num);
void SetStaffName(struct Staff *staffs, int index, char *name);
void PrintStaffsAskDayOffRecords(struct Staff staffs[], int totalStaffNum);

void SetStaffDayOff(struct Staff *staffs, int staffIndex, int day, enum dayOffType askDayOffType);
void ShowAskDayOff(enum dayOffType *askDayOff, int totalDays);