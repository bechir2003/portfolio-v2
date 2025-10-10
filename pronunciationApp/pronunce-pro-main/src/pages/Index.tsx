import { useState } from "react";
import { Button } from "@/components/ui/button";
import { Card } from "@/components/ui/card";
import { Mic, Play, RefreshCw, Languages, Volume2, Award, MessageSquare } from "lucide-react";
import { toast } from "sonner";

const Index = () => {
  const [currentSentence, setCurrentSentence] = useState("");
  const [currentVoice, setCurrentVoice] = useState("en-US-JennyNeural");
  const [isRecording, setIsRecording] = useState(false);
  const [isProcessing, setIsProcessing] = useState(false);
  const [score, setScore] = useState<number | null>(null);
  const [recognizedText, setRecognizedText] = useState("");
  const [audioUrl, setAudioUrl] = useState("");

  const [mediaRecorder, setMediaRecorder] = useState<MediaRecorder | null>(null);
  const [audioChunks, setAudioChunks] = useState<BlobPart[]>([]);

  const voices = [
    { name: "Jenny", code: "en-US-JennyNeural", lang: "en", flag: "🇺🇸", description: "US English - Female" },
    { name: "Guy", code: "en-US-GuyNeural", lang: "en", flag: "🇺🇸", description: "US English - Male" },
    { name: "Libby", code: "en-GB-LibbyNeural", lang: "en", flag: "🇬🇧", description: "UK English - Female" },
    { name: "Denise", code: "fr-FR-DeniseNeural", lang: "fr", flag: "🇫🇷", description: "French - Female" },
    { name: "Henri", code: "fr-FR-HenriNeural", lang: "fr", flag: "🇫🇷", description: "French - Male" },
  ];

  // Determine backend URL dynamically for local / ngrok
  const getBackendUrl = () => {
    if (window.location.hostname === "localhost" || window.location.hostname === "127.0.0.1") {
      return "http://127.0.0.1:8000";
    }
    return `https://${window.location.hostname}`;
  };

  const backendUrl = getBackendUrl();

  // Fetch a new practice phrase
  const getPhrase = async () => {
    try {
      const res = await fetch(`${backendUrl}/get_phrase/?voice=${currentVoice}`);
      const data = await res.json();
      setCurrentSentence(data.phrase);
      setAudioUrl(data.audio_url);

      const audio = new Audio(data.audio_url);
      audio.play();

      toast.success("New phrase loaded!");
    } catch (error) {
      toast.error("Failed to load phrase");
      console.error(error);
    }
  };

  // Preview selected voice
  const previewVoice = async (voice: string, language: string) => {
    try {
      const sampleText = language === "fr"
        ? "Bonjour, Je suis là pour vous aider avec votre prononciation française."
        : "Hello, I'm here to help you with your English pronunciation.";

      const res = await fetch(`${backendUrl}/preview_voice/`, {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ text: sampleText, voice })
      });

      const data = await res.json();
      const audio = new Audio(data.audio_url);
      audio.play();

      setCurrentVoice(voice);
      toast.success(`Voice changed to ${voice}`);
    } catch (error) {
      toast.error("Failed to preview voice");
      console.error(error);
    }
  };

  // Start recording
  const startRecording = async () => {
    if (!currentSentence) {
      toast.error("Please get a practice phrase first!");
      return;
    }

    try {
      const stream = await navigator.mediaDevices.getUserMedia({ audio: true });
      const recorder = new MediaRecorder(stream);
      const chunks: BlobPart[] = [];

      recorder.ondataavailable = (e) => chunks.push(e.data);

      recorder.onstop = async () => {
        setIsRecording(false);
        setIsProcessing(true);
        toast.info("Processing your pronunciation...");

        const blob = new Blob(chunks, { type: "audio/wav" });
        const formData = new FormData();
        formData.append("audio", blob);
        formData.append("sentence", currentSentence);

        try {
          const res = await fetch(`${backendUrl}/evaluate/`, { method: "POST", body: formData });
          const result = await res.json();

          setScore(result.score);
          setRecognizedText(result.recognized_text);
          setIsProcessing(false);

          if (result.score >= 80) toast.success("Excellent pronunciation!");
          else if (result.score >= 60) toast.success("Good job!");
          else toast.info("Keep practicing!");
        } catch (error) {
          toast.error("Failed to evaluate pronunciation");
          setIsProcessing(false);
          console.error(error);
        }
      };

      recorder.start();
      setMediaRecorder(recorder);
      setAudioChunks(chunks);
      setIsRecording(true);
      toast.info("Recording... Speak now!");
    } catch (error) {
      toast.error("Error accessing microphone");
      console.error(error);
    }
  };

  // Stop recording manually
  const stopRecording = () => {
    if (mediaRecorder && mediaRecorder.state === "recording") {
      mediaRecorder.stop();
      mediaRecorder.stream.getTracks().forEach((track) => track.stop());
    }
  };

  // Score styling
  const getScoreClass = (score: number) => {
    if (score >= 80) return "score-excellent";
    if (score >= 60) return "score-good";
    return "score-poor";
  };

  const getScoreLabel = (score: number) => {
    if (score >= 80) return "Excellent!";
    if (score >= 60) return "Good Job";
    return "Needs Practice";
  };

  return (
    <div className="min-h-screen p-6 md:p-8 lg:p-12">
      <div className="max-w-7xl mx-auto">
        {/* Header */}
        <header className="text-center mb-12 animate-fade-in">
          <link rel="icon" type="image/svg+xml" href="/favicon.svg" />

          <div className="flex items-center justify-center gap-4 mb-4">
            <div className="w-16 h-16 rounded-full bg-gradient-to-br from-primary to-secondary flex items-center justify-center shadow-lg">
              <Languages className="w-8 h-8 text-white" />
            </div>
            <h1 className="text-5xl font-bold bg-gradient-to-r from-primary to-secondary bg-clip-text text-transparent">
              LinguaPro Coach
            </h1>
          </div>
          <p className="text-xl text-muted-foreground">AI-powered pronunciation training for language professionals</p>
        </header>

        {/* Main Content Grid */}
        <div className="grid lg:grid-cols-2 gap-8">
          {/* Left Column */}
          <div className="space-y-8">
            {/* Practice Phrase Card */}
            <Card className="card-elevated p-8 animate-fade-in">
              <div className="flex items-center gap-3 mb-6">
                <MessageSquare className="w-6 h-6 text-primary" />
                <h2 className="text-2xl font-bold">Practice Phrase</h2>
              </div>

              <div className="bg-gradient-to-br from-primary/5 to-secondary/5 border-l-4 border-primary rounded-lg p-6 mb-6 min-h-[120px] flex items-center justify-center">
                <p className="text-xl font-medium text-center">
                  {currentSentence || "Click the button below to get a practice phrase"}
                </p>
              </div>

              {audioUrl && (
                <audio controls className="w-full mb-6 rounded-lg">
                  <source src={audioUrl} type="audio/mpeg" />
                </audio>
              )}

              <Button onClick={getPhrase} className="w-full btn-primary py-6 text-lg">
                <RefreshCw className="w-5 h-5 mr-2" /> Get New Phrase
              </Button>
            </Card>

            {/* Recording Card */}
            <Card className="card-elevated p-8 animate-fade-in">
              <div className="flex items-center gap-3 mb-6">
                <Mic className="w-6 h-6 text-destructive" />
                <h2 className="text-2xl font-bold">Pronunciation Practice</h2>
              </div>

              <div className="flex gap-4 mb-6">
                <Button
                  onClick={startRecording}
                  disabled={isRecording || isProcessing}
                  className="flex-1 btn-destructive py-6 text-lg"
                >
                  <Mic className="w-5 h-5 mr-2" /> Start Recording
                </Button>

                <Button
                  onClick={stopRecording}
                  disabled={!isRecording}
                  className="flex-1 btn-secondary py-6 text-lg"
                >
                  Stop Recording
                </Button>
              </div>

              {isProcessing && (
                <div className="bg-primary/10 text-primary rounded-lg p-4 text-center font-semibold">
                  Processing your pronunciation...
                </div>
              )}

              {score !== null && (
                <div className="text-center space-y-4 animate-scale-in">
                  <div className="flex items-center justify-center gap-2">
                    <Award className="w-8 h-8 text-muted-foreground" />
                    <h3 className="text-xl font-bold">Pronunciation Score</h3>
                  </div>
                  <div className={`text-7xl font-bold ${getScoreClass(score)}`}>{score.toFixed(1)}</div>
                  <div className="text-2xl font-semibold">{getScoreLabel(score)}</div>

                  {recognizedText && (
                    <div className="bg-muted rounded-lg p-4 mt-6">
                      <p className="text-sm text-muted-foreground mb-1">You said:</p>
                      <p className="italic text-lg">{recognizedText}</p>
                    </div>
                  )}
                </div>
              )}
            </Card>
          </div>

          {/* Right Column - Voice Selection */}
          <div className="space-y-8">
            <Card className="card-elevated p-8 animate-fade-in">
              <div className="flex items-center gap-3 mb-6">
                <Volume2 className="w-6 h-6 text-primary" />
                <h2 className="text-2xl font-bold">Voice Selection</h2>
              </div>

              <div className="space-y-4">
                {voices.map((voice) => (
                  <div
                    key={voice.code}
                    className={`p-5 rounded-xl border-2 transition-all duration-300 cursor-pointer hover:shadow-md ${
                      currentVoice === voice.code
                        ? "border-primary bg-primary/5 shadow-md"
                        : "border-border hover:border-primary/50"
                    }`}
                  >
                    <div className="flex items-center justify-between mb-3">
                      <div className="flex items-center gap-3">
                        <span className="text-3xl">{voice.flag}</span>
                        <div>
                          <h3 className="font-bold text-lg">{voice.name}</h3>
                          <p className="text-sm text-muted-foreground">{voice.description}</p>
                        </div>
                      </div>
                    </div>

                    <div className="flex items-center gap-2 mb-3">
                      <code className="text-xs bg-muted px-3 py-1 rounded font-mono">{voice.code}</code>
                    </div>

                    <Button
                      onClick={() => previewVoice(voice.code, voice.lang)}
                      variant="outline"
                      className="w-full"
                    >
                      <Play className="w-4 h-4 mr-2" /> Preview Voice
                    </Button>
                  </div>
                ))}
              </div>
            </Card>
          </div>
        </div>

        {/* Footer */}
        <footer className="text-center mt-12 pt-8 border-t border-border">
          <p className="text-muted-foreground">
            LinguaPro Coach © 2023 | Professional Pronunciation Training
          </p>
        </footer>
      </div>
    </div>
  );
};

export default Index;
