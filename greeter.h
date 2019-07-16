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
    THIS_DAY_DOES_NOT_EXIST = -1,
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
    enum dayOffType askDayOff[31]; // save record of day1 at [0], day2 at [1], ..., day12 at [11]
    int startWorkingYear;
};

struct RequirmentInMonth
{
    const char *month;
    int totalDaysInMonth;     // TODO it might be 28 / 29 days in Frb.  -> couldn't use map to link month to total number of days
    int staffsRequirment[31]; //choose either staffsRequirment or staffsCouldTakeDayOff
    int staffsCouldTakeDayOff[31];
    ////TOOD should save the names who take day off
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

struct RequirmentInMonth *CreateRequirmentInMonth();
void SetRequirmentMonth(struct RequirmentInMonth *requirmentInMonth, char *month, int totalDaysInMonth);
void PrintRequirment(struct RequirmentInMonth *requirmentInMonth);