package main

// #cgo CFLAGS: -g -Wall
// #include <stdlib.h>
// #include "greeter.h"
import "C"
import (
	"fmt"
)

func main() {

	var r, blue, y C.enum_color = C.RED, C.BLUE, C.YELLO
	fmt.Println(r, blue, y)
}
