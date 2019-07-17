#define MAX_DAYS_IN_ONE_MONTH 31

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
    int startWorkingYear;
    enum title position;
    enum specialStatus status;
    enum dayOffType wannaDayOffList[MAX_DAYS_IN_ONE_MONTH]; // day1 at [0], day2 at [1], ..., day12 at [11]
};

struct RequirmentInMonth
{
    const char *month;
    int totalDaysInMonth;                        // couldn't use map / dictionary structure -> it might be 28 / 29 days in Frb
    int staffsRequirment[MAX_DAYS_IN_ONE_MONTH]; //choose either staffsRequirment or staffsCouldTakeDayOff
    int staffsCouldTakeDayOff[MAX_DAYS_IN_ONE_MONTH];
    ////TOOD should save the names who take day off
};

int greet(struct Staff *g, char *out);

struct Staff *createStaffs(int num);
void setStaffName(struct Staff *staffs, int index, char *name);
void printStaffsWannaDayOffList(struct Staff staffs[], int totalStaffNum);
void setStaffDayOff(struct Staff *staffs, int staffIndex, int day, enum dayOffType askDayOffType);
void showWannaDayOffList(enum dayOffType *wannaDayOffList, int totalDays);

struct RequirmentInMonth *createRequirmentInMonth();
void setRequirmentMonth(struct RequirmentInMonth *requirmentInMonth, char *month, int totalDaysInMonth);
void printRequirment(struct RequirmentInMonth *requirmentInMonth);