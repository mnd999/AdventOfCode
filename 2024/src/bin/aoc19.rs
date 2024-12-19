use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 

    let mut towels: Vec<String> = Vec::new();

    let mut line = 0;
    let mut success = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let mut stack: Vec<&str> = Vec::new();
        println!("line {}", line);

        if line == 0 {
            let cols: Vec<&str> = buffer.split_whitespace().collect();
            for t in cols {
                let t2 = t.replace(",", "");
                towels.push(t2);
            }

            println!("towels {:?}", &towels);
        } else if line > 1 {
            stack.push(&buffer.trim());
            let mut done = false;
            while !stack.is_empty() && !done {
                print!("Stack {:?}\n", stack);
                let v = stack.pop().unwrap();
                for t in &towels {
                    if v == t {
                        success +=1;
                        done = true;
                    } else {
                        v.strip_prefix(t).map(|c| stack.push(c));
                    }
                }

            }

        }

        buffer = String::new();
        line = line + 1;
    }

    print!("Part 1: {}\n", success);

    Ok(())
}