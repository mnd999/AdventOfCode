use std::io;

fn main() -> io::Result<()> {
    let lines = io::stdin().lines();

    let mut keys: Vec<Vec<i64>> = Vec::new();
    let mut locks: Vec<Vec<i64>> = Vec::new();

    let mut state = 0;
    let mut line_count = 0;
    let mut working: Vec<i64> = Vec::new();
    for line in lines {
        let l = line.unwrap();
        if l.len() == 0 {
            println!("{:?}", working);
            if state == -1 {
                keys.push(working);
            } else  if state == 1 {
                locks.push(working);
            }
            state = 0;
            line_count = 0;
            working = Vec::new();
        }
        else if state == 0 && l.contains("#") {
            println!("Got lock");
            state = 1;
        } else if state == 0 {
            println!("Got key");
            state = -1;
        } else if state == 1 || line_count < 5  {
            let mut i = 0;
            for c in l.chars() {
                if working.len() == i {
                    working.push(0);
                }
                if c == '#' {
                    working[i] +=1;
                }
                i += 1;
            }
            line_count +=1;
        }

        println!("got a line: {}", l);
    }
    if state == -1 {
        keys.push(working);
    } else  if state == 1 {
        locks.push(working);
    }

    println!("Keys: {:?}", keys);
    println!("Locks: {:?}", locks);


    let mut total1 = 0;
    for key in keys {
        for lock in &locks {
            if overlap(&key, &lock) {
                total1 +=1;
            }
        }
    }

    println!("Total1: {}", total1);

    Ok(())
}

fn overlap(key: &Vec<i64>, lock: &Vec<i64>) -> bool {

    let mut i = 0;
    while i < key.len() {
        if key[i] + lock[i] > 5 {
            return false;
        }
        i +=1;
    }

    return true;
}