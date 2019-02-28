package com.aerserv.offheapmap;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.concurrent.atomic.AtomicBoolean;


public class NLibLoader {

    private static final AtomicBoolean loaded = new AtomicBoolean(false);

    public static void loadLibIfNotLoaded() {

        if (loaded.compareAndSet(false, true)) {

            // Let's export the embedded native lib to java.library.path 
            String libPath = System.getProperty("java.library.path");
            //if this is set to true we will not delete the lib on exit.  any other case we delete it
            if(libPath.equals("")) {
                //if it's not set we are done
                System.err.println("java.library.path not set. That's fatal yo!");
                System.exit(1);
            }
            
            //determine lib type based on OS
            String ext = "so";
            if(System.getProperty("os.name").equals("Mac OS X")) {
                ext = "dylib";
            }

            //The lib name and path inside the jar
            String ePath = "/liboffheapmap." + ext; 
            //THe destination path
            File fsPath = new File(libPath + ePath);
            fsPath.deleteOnExit();

            //let's try to unzip the libs to the libPath
            try (InputStream is = SsOhMap.class.getResourceAsStream(ePath)) {
                Files.copy(is, fsPath.toPath(), StandardCopyOption.REPLACE_EXISTING);
            } catch (IOException e) {
                //We can't continue
                System.err.println("offheapmap lib not found!");
                e.printStackTrace();
                System.exit(1);
            }

            //And finally load it to do stuff
            System.loadLibrary("offheapmap");
        }

    }

}