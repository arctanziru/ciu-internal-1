package com.example.aplikasi;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.aplikasi.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'aplikasi' library on application startup.
    static {
        System.loadLibrary("aplikasi");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.encryptButton.setOnClickListener(v -> {
            var value = binding.editText.getText().toString();
            if (value.isEmpty()) {
                return;
            }

            var encryptedText = encryptPlainText(getResources().getString(R.string.whenyh), value);
            System.out.println("Encrypted text: " + encryptedText);

            TextView tv = binding.sampleText;
            tv.setText(encryptedText);
        });

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'aplikasi' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
    public native String encryptPlainText(String whenYh, String plainText);
}