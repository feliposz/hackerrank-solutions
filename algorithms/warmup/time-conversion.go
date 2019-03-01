package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strings"
)

/*
 * Complete the timeConversion function below.
 */
func timeConversion(s string) string {
    var hr, mi, sc int
    var period string
    fmt.Sscanf(s, "%2d:%2d:%2d%s", &hr, &mi, &sc, &period)
    if period == "PM" && hr != 12 {
        hr += 12
    }
    if (period == "AM" && hr == 12) {
        hr = 0
    }
    result := fmt.Sprintf("%02d:%02d:%02d", hr, mi, sc)
    return result
}

func main() {
    reader := bufio.NewReaderSize(os.Stdin, 1024 * 1024)

    outputFile, err := os.Create(os.Getenv("OUTPUT_PATH"))
    checkError(err)

    defer outputFile.Close()

    writer := bufio.NewWriterSize(outputFile, 1024 * 1024)

    s := readLine(reader)

    result := timeConversion(s)

    fmt.Fprintf(writer, "%s\n", result)

    writer.Flush()
}

func readLine(reader *bufio.Reader) string {
    str, _, err := reader.ReadLine()
    if err == io.EOF {
        return ""
    }

    return strings.TrimRight(string(str), "\r\n")
}

func checkError(err error) {
    if err != nil {
        panic(err)
    }
}

