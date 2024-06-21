use std::io::{self, Write};
use std::thread;
use std::time::Duration;

fn main() {

    fn showtime(seconds: f64) -> String {
        
        let hours = seconds as u32 / 3600; // Convert seconds to hours (integer division)
        let remaining_seconds = seconds % 3600.0; // Get remaining seconds after hours calculation

        let minutes = remaining_seconds as u32 / 60; // Convert remaining seconds to minutes
        let seconds = remaining_seconds % 60.0; // Get remaining seconds after minutes calculation

        // Format the output string with leading zeros for hours and minutes
        format!("{:02}:{:02}:{:.2}", hours, minutes, seconds)
    }

    println!("How many seconds would you like to cronometer?: ");

    let mut received = String::new();
    let mut res: f64 = 0.0;
    
    match io::stdin().read_line(&mut received) { // input line and parse to float
        Ok(_) => {
            res = match received.trim().parse::<f64>() {
                Ok(num) => num,
                Err(_) => {
                    println!("Error: Invalid input. Please enter a number of seconds.");
                    return;
                }
            };
        }
        Err(err) => println!("Error: {}", err),
    }

    while res > 0.0 {
        write!(io::stdout(), "\x1B[F").unwrap(); // move cursor up one line
        write!(io::stdout(), "\x1B[K").unwrap(); // clear the current line
        println!("{}", showtime(res)); // print the clock
        thread::sleep(Duration::from_millis(10)); // waits
        res -= 0.01;
    }

    println!("ended.");
}
