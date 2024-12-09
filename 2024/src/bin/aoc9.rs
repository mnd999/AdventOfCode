use std::io;
use std::collections::VecDeque;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 

    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {
    }

    let exp = expand_input(&buffer.trim());

    println!("{:?}", exp);

    let defrag = defrag(exp.clone());
    let defrag2 = defrag2(exp);

    println!("{:?}", defrag2);

    print!("Part 1: {}\n", checksum(&defrag));


    print!("Part 2: {}\n", checksum(&defrag2));

    Ok(())
}

fn checksum(input: &Vec<i16>) -> u64 {
    let mut total: u64 = 0;
    let mut i = 0;
    while i < input.len() {
        let f = u64::try_from(input[i]).unwrap_or(0);
        total = total + u64::from(u64::try_from(i).unwrap() * f);
        i = i + 1;
    }
    return total;
}

fn defrag(mut input: VecDeque<i16>) -> Vec<i16> {
    let mut out: Vec<i16> = Vec::new();

    while !input.is_empty() {
        let f = input.pop_front().unwrap();
        if f >= 0 {
            out.push(f);
        } else {
            let mut e = input.pop_back();
            if e.is_some() {
                while e.is_some() && e.unwrap() < 0 {
                    e = input.pop_back();
                }
                if e.is_some() { out.push(e.unwrap()) };
            }
        }
    }
    return out;
}


fn defrag2(mut input: VecDeque<i16>) -> Vec<i16> {

    let mut epos = input.len() -1;
    let mut file_no = i16::MAX;
    while (epos > 0 && file_no > 1) {

        // skip space
        if input[epos] == -1 || input[epos] > file_no { 
            epos = epos -1;
            continue 
        }

        // get file to move
        file_no = input[epos];
        let mut file_length = 1;
        while epos > 0 && input[epos-1] == file_no {
            file_length+=1;
            epos-=1;
        }
        epos-=1;

        println!("fileno {} ln {}", file_no, file_length);

        let mut spos = 0;
        let mut scnt = 0;
        while spos <= epos && scnt < file_length {
            if input[spos] == -1 {
                scnt+=1;
            } else {
                scnt = 0;
            }

            if scnt == file_length {
                let mut w = 0;
                while w < file_length {
                    input[spos-w] = file_no;
                    input[epos+w+1] = -1;
                    w+=1;
                }
            }

            spos+=1;
        }

        //println!("{:?}", input);
    }
    
    return Vec::from(input);
}


fn expand_input(input: &str) -> VecDeque<i16> {

    let mut expanded: VecDeque<i16> = VecDeque::new();

    let mut filecnt = 0;
    let mut state = 1;

    for c in input.chars() {
        let n = i16::try_from(c.to_digit(10).unwrap()).unwrap();
        let mut i = 0;
        while i < n {
            if state == 1 {
                expanded.push_back(filecnt);
            } else {
                expanded.push_back(-1);
            }
            i = i + 1;
        }
        if state == 1 {
            filecnt = filecnt + 1;
        }
        state = -state;
    }
    return expanded;

}  