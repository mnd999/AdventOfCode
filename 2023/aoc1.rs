use std::io;
use std::io::Write;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 
    let mut codes: Vec<i32> = Vec::new();

    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        buffer = replace_words(&buffer);  // part 2
        let digits = buffer.chars().filter(|c| c.is_digit(10)).collect::<Vec<_>>();
        let code = format!("{}{}", digits[0], digits[digits.len()-1]);
        print!("{}\n", code);
        codes.push(code.parse::<i32>().unwrap());
        buffer = String::new();
    }
    
    let total :i32 = codes.iter().sum();
    print!("{}", total);

    Ok(())
}

fn replace_words(line : &String) -> String {

    let replacements = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];

    let mut buffer:String = line.clone();
    print!("b1: {}\n", line);
    for (pos,r) in replacements.iter().enumerate() {
        let matches: Vec<_> = line.match_indices(r).collect();
        if matches.len() > 0 {
            let mut result = buffer.clone();
            for (m,_) in matches {
                result = format!("{}{}{}", result[0..m].to_string(), &(pos+1).to_string(), buffer[m+1..buffer.len()].to_string());
                print!("r1: {}\n", result);
            }
            //print!("r2: {}\n", result);
            buffer = result;
        }
    }
    print!("b: {}\n", buffer);
    let _ = io::stdout().flush();
    return buffer;
}

