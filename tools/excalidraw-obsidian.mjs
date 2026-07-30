import { randomUUID } from "node:crypto";
import { spawnSync } from "node:child_process";
import {
  existsSync,
  mkdirSync,
  readFileSync,
  readdirSync,
  renameSync,
  statSync,
  unlinkSync,
  writeFileSync,
} from "node:fs";
import { tmpdir } from "node:os";
import { dirname, join, resolve } from "node:path";
import { fileURLToPath } from "node:url";

const scriptDir = dirname(fileURLToPath(import.meta.url));
const defaultOutputDir =
  process.env.EXCALIDRAW_OBSIDIAN_DIR ||
  join(process.env.USERPROFILE || process.cwd(), "Desktop", "GodNotes", "excalidraw");

function timestamp() {
  const now = new Date();
  const pad = (value) => String(value).padStart(2, "0");
  return [
    now.getFullYear(),
    "-",
    pad(now.getMonth() + 1),
    "-",
    pad(now.getDate()),
    " ",
    pad(now.getHours()),
    ".",
    pad(now.getMinutes()),
    ".",
    pad(now.getSeconds()),
  ].join("");
}

function usage() {
  return [
    "Usage:",
    "  excalidraw-obsidian",
    "  excalidraw-obsidian <output-file-or-directory>",
    "  excalidraw-obsidian --out <output-file-or-directory>",
    "",
    `Default directory: ${defaultOutputDir}`,
  ].join("\n");
}

function resolveOutputPath(args) {
  if (args.includes("--help") || args.includes("-h")) {
    console.log(usage());
    process.exit(0);
  }

  let requested;
  if (args[0] === "--out") {
    requested = args[1];
    if (!requested || args.length > 2) {
      throw new Error(`Invalid arguments.\n${usage()}`);
    }
  } else if (args.length <= 1) {
    requested = args[0];
  } else {
    throw new Error(`Invalid arguments.\n${usage()}`);
  }

  if (!requested) {
    return join(defaultOutputDir, `${timestamp()}.excalidraw.md`);
  }

  const absolute = resolve(requested);
  if (existsSync(absolute) && statSync(absolute).isDirectory()) {
    return join(absolute, `${timestamp()}.excalidraw.md`);
  }

  const lower = absolute.toLowerCase();
  if (lower.endsWith(".excalidraw.md")) {
    return absolute;
  }
  if (lower.endsWith(".excalidraw")) {
    return `${absolute}.md`;
  }
  return `${absolute}.excalidraw.md`;
}

function obsidianDocument(scene) {
  const drawing = JSON.stringify(scene, null, 2);
  return [
    "---",
    "excalidraw-plugin: parsed",
    "tags: [excalidraw]",
    "---",
    "",
    "# Excalidraw Data",
    "",
    "## Text Elements",
    "",
    "%%",
    "## Drawing",
    "```json",
    drawing,
    "```",
    "%%",
    "",
  ].join("\n");
}

function findCliEntry() {
  const packageRoots = [
    resolve(scriptDir, "..", "mcp-excalidraw-server"),
    join(
      process.env.USERPROFILE || process.cwd(),
      ".codex",
      "tools",
      "mcp-excalidraw-server",
    ),
  ];

  for (const globalDir of packageRoots) {
    if (!existsSync(globalDir)) continue;
    for (const major of readdirSync(globalDir, { withFileTypes: true })) {
      if (!major.isDirectory()) continue;
      const majorDir = join(globalDir, major.name);
      for (const build of readdirSync(majorDir, { withFileTypes: true })) {
        if (!build.isDirectory()) continue;
        const entry = join(
          majorDir,
          build.name,
          "node_modules",
          "mcp-excalidraw-server",
          "dist",
          "bin.js",
        );
        if (existsSync(entry)) return entry;
      }
    }
  }
  return undefined;
}

function main() {
  const outputPath = resolveOutputPath(process.argv.slice(2));
  if (existsSync(outputPath)) {
    throw new Error(`Refusing to overwrite existing file: ${outputPath}`);
  }

  const rawPath = join(tmpdir(), `excalidraw-${randomUUID()}.excalidraw`);
  const pendingPath = `${outputPath}.tmp-${randomUUID()}`;

  try {
    const cliEntry = findCliEntry();
    if (!cliEntry) {
      throw new Error("Unable to find the installed mcp-excalidraw-server CLI");
    }
    const exportResult = spawnSync(process.execPath, [cliEntry, "export", "--out", rawPath], {
      encoding: "utf8",
      windowsHide: true,
    });

    if (exportResult.status !== 0) {
      const details = (exportResult.stderr || exportResult.stdout || "").trim();
      throw new Error(`Excalidraw CLI export failed${details ? `: ${details}` : ""}`);
    }

    const scene = JSON.parse(readFileSync(rawPath, "utf8"));
    if (scene.type !== "excalidraw" || !Array.isArray(scene.elements)) {
      throw new Error("CLI returned an invalid Excalidraw scene");
    }

    mkdirSync(dirname(outputPath), { recursive: true });
    writeFileSync(pendingPath, obsidianDocument(scene), {
      encoding: "utf8",
      flag: "wx",
    });
    renameSync(pendingPath, outputPath);

    console.log(
      JSON.stringify(
        {
          success: true,
          file: outputPath,
          format: "obsidian-excalidraw",
          elements: scene.elements.length,
        },
        null,
        2,
      ),
    );
  } finally {
    if (existsSync(rawPath)) unlinkSync(rawPath);
    if (existsSync(pendingPath)) unlinkSync(pendingPath);
  }
}

try {
  main();
} catch (error) {
  console.error(error instanceof Error ? error.message : String(error));
  process.exitCode = 1;
}
