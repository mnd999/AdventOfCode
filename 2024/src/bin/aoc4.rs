use std::io;

fn main() -> io::Result<()> {
    let mut buffer = String::new();
    let stdin = io::stdin(); 


    let mut puzzle = Vec::new();

    let mut rowCnt = 0;
    // Read in the puzzle
    while stdin.read_line(&mut buffer).is_ok_and(|x| x > 1) {

        let mut row = Vec::new();

        let mut i = 0;
        for c in buffer.chars() {
            row.push(c);    
            i = i + 1;
        }

        buffer = String::new();
        puzzle.push(row);
        rowCnt = rowCnt + 1;
    }


    print!("{:?}", puzzle);

    Ok(())
}
