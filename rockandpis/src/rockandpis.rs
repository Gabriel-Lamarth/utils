use rand::Rng;

fn main() {

    println!("Choice:\n-> Rock\n-> Paper\n-> Scisor"); // user options

    // let _=stdout().flush(); // clean the std in
    
    let mut user_input = String::new(); // Create the variable for user's input

    std::io::stdin().read_line(&mut user_input).expect("Failed reading the line"); // terminal input

    user_input = user_input.trim().to_lowercase(); // trim and turn it all lowercase

    let mut rng = rand::thread_rng(); // machine choice config
    let computer: u8 = rng.gen_range(0..=2); // machine choice betwen 0 and 2

    if is_valid(&user_input){
        
        let com_str: &str;
        
        match computer {
            0 => com_str = "rock",
            1 => com_str = "paper",
            2 => com_str = "scisor",
            _ => {
                println!("Intern error;\n Exiting program.\n");
                return
            },
        }

        print_win(&user_input, com_str);
    
    } else {
        println!("Your choice isn't valid. exiting program.");
    }
}

fn is_valid(u_inp: &str) -> bool { // verify if the input is valid;
    const VALID: [&str; 3] = ["rock", "paper", "scisor"];
    
    for e in VALID.iter() { // for each valid element
        if *e == u_inp { // verify if the value of the input is valid
            return true; // return true in this case
        }
    }
    false // return false else
}

fn print_win(usr: &str, com: &str){
    println!("Your choice: {}\nComputer choice: {}\n", usr, com);

    if usr == com {
        println!("There is a Tie!");
    } else if usr == "paper" && com == "rock" || usr == "rock" && com == "scisor" || usr == "scisor" && com == "paper" {
        println!("You win!");
    } else {
        println!("The machine wins :(");
    }

}
