use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 
    let mut safe = 0;
    let mut safe2 = 0;

    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {
        let cols: Vec<&str> = buffer.split_whitespace().collect();

        if is_row_safe(&cols) {
            safe = safe + 1;
        }


        if is_row_safe2(&cols) {
            safe2 = safe2 + 1;
        }

        print!("\n");
        buffer = String::new();
    }

    print!("Part 1: {}\n", safe);


    print!("Part 2: {}\n", safe2);

    Ok(())
}


fn is_row_safe(cols :&Vec<&str>) -> bool { 

    let mut dir = 0;
    let mut last_num = cols[0].parse::<i32>().unwrap();
    // print!("{}", last_num);

    let mut s = true;
    let mut i = 1;
    while i < cols.len() {
        let num = cols[i].parse::<i32>().unwrap();
        let diff = last_num - num;
        
        // check gap
        if diff.abs() > 3 {
            s = false;
        }

        // check difference
        if dir == 0 {
            dir = diff;
        }
        if (dir < 0  && diff >= 0) || (dir > 0 && diff <= 0) || diff == 0 {
            s = false;
        }
        // print!("( {}, {}, {})", num, diff, s);

        last_num = num;
        i = i + 1;
    }

    return s;
}

fn is_row_safe2(cols : &Vec<&str>) -> bool { 

    if is_row_safe(cols) {
        return true;
    }

    let mut i = 0;
    while i < cols.len() {
        let mut nc : Vec<&str> = Vec::new();
        let mut j = 0;
        while j < cols.len() {
            if j != i {
                nc.push(cols[j])
            }
            j = j + 1
        }        
        if is_row_safe(&nc) {
            return true;
        }
        print!("{:?}", nc);
        i = i + 1;
    }

    return false;

}
