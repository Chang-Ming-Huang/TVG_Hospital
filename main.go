package main

// #cgo CFLAGS: -g -Wall
// #include <stdlib.h>
// #include "greeter.h"
// #include "staffInfo.h"
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	//howToUseBasicFunctions()

	var requirmentInMonth *C.struct_RequirmentInMonth = C.createRequirmentInMonth()

	var totalStaffNum = C.int(5)
	var staffs *C.struct_Staff = C.createStaffs(totalStaffNum)

	setRequirment(requirmentInMonth)
	setUserInfo(staffs, requirmentInMonth)

	C.printRequirment(requirmentInMonth)
	C.printStaffsWannaDayOffList(staffs, totalStaffNum)
}

func setRequirment(requirmentInMonth *C.struct_RequirmentInMonth) {
	//C.setRequirmentMonth(requirmentInMonth, C.CString("JULY"), C.int(31))
	C.setRequirmentMonth(requirmentInMonth, C.CString("FEB"), C.int(28))
}

func setUserInfo(staffs *C.struct_Staff, requirmentInMonth *C.struct_RequirmentInMonth) {
	var staffIndex = 0
	firstPerson := C.CString("Lee")
	C.setStaffName(staffs, C.int(staffIndex), firstPerson)

	setDefultDayOffValue(staffs, staffIndex, int(requirmentInMonth.totalDaysInMonth))
	C.setStaffDayOff(staffs, C.int(staffIndex), 2, C.RED_LINE)
	C.setStaffDayOff(staffs, C.int(staffIndex), 5, C.GREEN_LINE)
	C.setStaffDayOff(staffs, C.int(staffIndex), 7, C.VACATION_RESERVATION)

	staffIndex = 1
	secondPerson := C.CString("Huang")
	C.setStaffName(staffs, C.int(staffIndex), secondPerson)

	setDefultDayOffValue(staffs, staffIndex, int(requirmentInMonth.totalDaysInMonth))
	C.setStaffDayOff(staffs, C.int(staffIndex), 3, C.RED_LINE)
	C.setStaffDayOff(staffs, C.int(staffIndex), 5, C.GREEN_LINE)
	C.setStaffDayOff(staffs, C.int(staffIndex), 8, C.VACATION_RESERVATION)

}

func setDefultDayOffValue(staffs *C.struct_Staff, staffIndex int, endDayOfMonth int) {

	for day := 0; day < endDayOfMonth; day++ {
		C.setStaffDayOff(staffs, C.int(staffIndex), C.int(day), C.WORKING)
	}

	for daysDoesNotExist := endDayOfMonth + 1; daysDoesNotExist <= C.MAX_DAYS_IN_ONE_MONTH; daysDoesNotExist++ {
		C.setStaffDayOff(staffs, C.int(staffIndex), C.int(daysDoesNotExist), C.THIS_DAY_DOES_NOT_EXIST)
	}

}

func howToUseBasicFunctions() {
	staffName := C.CString("Second Gopher")
	defer C.free(unsafe.Pointer(staffName))

	year := C.int(2018)

	g := C.struct_Staff{
		name:             staffName,
		startWorkingYear: year,
	}

	ptr := C.malloc(C.sizeof_char * 1024)
	defer C.free(unsafe.Pointer(ptr))

	size := C.greet(&g, (*C.char)(ptr))

	b := C.GoBytes(ptr, size)
	fmt.Println(string(b))

	//https://studygolang.com/articles/16825
	var arr *C.int = C.createArray(5)
	C.setArrValue(arr, 0, 100)
	C.printArray(arr, 5)
}
