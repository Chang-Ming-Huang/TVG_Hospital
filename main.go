package main

// #cgo CFLAGS: -g -Wall
// #include <stdlib.h>
// #include "greeter.h"
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	//howToUseBasicFunctions()

	var staffs *C.struct_Staff = C.CreateStaffs(5)
	setUserInfo(staffs)
	C.PrintStaffsAskDayOffRecords(staffs, 5)
}

func setUserInfo(staffs *C.struct_Staff) {
	var staffIndex = 0
	firstPerson := C.CString("Lee")
	C.SetStaffName(staffs, C.int(staffIndex), firstPerson)

	setDefultDayOffValue(staffs, staffIndex)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 2, C.RED_LINE)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 5, C.GREEN_LINE)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 7, C.VACATION_RESERVATION)

	staffIndex = 1
	secondPerson := C.CString("Huang")
	C.SetStaffName(staffs, C.int(staffIndex), secondPerson)

	setDefultDayOffValue(staffs, staffIndex)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 3, C.RED_LINE)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 5, C.GREEN_LINE)
	C.SetStaffDayOff(staffs, C.int(staffIndex), 8, C.VACATION_RESERVATION)
}

func setDefultDayOffValue(staffs *C.struct_Staff, staffIndex int) {
	for day := 0; day < 31; day++ {
		C.SetStaffDayOff(staffs, C.int(staffIndex), C.int(day), C.WORKING)
	}
}

func howToUseBasicFunctions() {
	name := C.CString("Second Gopher")
	defer C.free(unsafe.Pointer(name))

	year := C.int(2018)

	g := C.struct_Staff{
		name: name,
		year: year,
	}

	ptr := C.malloc(C.sizeof_char * 1024)
	defer C.free(unsafe.Pointer(ptr))

	size := C.greet(&g, (*C.char)(ptr))

	b := C.GoBytes(ptr, size)
	fmt.Println(string(b))

	//https://studygolang.com/articles/16825
	var arr *C.int = C.CreateArray(5)
	C.SetArrValue(arr, 0, 100)
	C.PrintArray(arr, 5)
}
