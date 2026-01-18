use std::io;

fn get_data(count: usize) -> Vec<usize> {

    // Memory created on heap
    let mut data = Vec::new();

    for i in 0..count {
        data.push(i * 2);
    }

    // Ownership of memory passed to the caller
    return data;
}

fn get_size(data: &Vec<usize>) -> usize {
    // Data is borrowed here
    return data.len();
}

fn main() {
    let mut temp = String::new();

    println!("Application starting");

    println!("Press any key to setup large memory use");
    
    io::stdin().read_line(&mut temp).unwrap();

    // Ownership to memory now resides with data in main
    let data = get_data(1000000);

    println!("Data ready");
    println!("Size: {}", data.len());

    let count = get_size(&data);
    println!("Size borrowing function: {}", count);

    println!("data still owns the memory: val at 10 - {}", data.get(10).unwrap());

    // No explicit free of memory
    // Rust compiler will add the necessary drops

    println!("Press any key to exit");
    io::stdin().read_line(&mut temp).unwrap();
    
}
