use std::fs;
use std::path::Path;

fn main() {
    let files = [
        ("src/aircraft.rs", "aerodisspace-aircraft-controller/src/aircraft"),
        ("src/controller.rs", "aerodisspace-aircraft-controller/src/controller"),
    ]; // (src_file, target_dir)

    // Collect the source files to be compiled by cxx_build
    let source_files: Vec<&str> = files.iter().map(|f| f.0).collect();

    // Compile the source files
    cxx_build::bridges(source_files).compile("aerodisspace_aircraft_controller");

    // rerun-if-changed
    println!("cargo:rerun-if-changed=src/aircraft.rs");
    println!("cargo:rerun-if-changed=src/controller.rs");

    // path to the generated C++ files
    let generated_c_files = Path::new("./target/cxxbridge/aerodisspace_aircraft_controller/src");

    // Copy the generated C++ files to the target directories
    for (src_file, target_dir) in &files {
        let src_file_stem = Path::new(src_file).file_stem().unwrap();
        let dest_dir = Path::new(target_dir);
        
        for extension in &["rs.h", "rs.cc"] {
            let src_file_name = format!("{}.{}", src_file_stem.to_str().unwrap(), extension);
            let src_path = generated_c_files.join(&src_file_name);
            let dest_path = dest_dir.join(&src_file_name);
            println!("FILE_NAME: {} | SRC_PATH: {:?} | DEST_PATH: {:?}", src_file_name, src_path, dest_path);
            fs::copy(&src_path, &dest_path).expect("Failed to copy file");
        }
    }
}

// set CARGO_BUILD_SCRIPT_DEBUG=1 && cargo build
